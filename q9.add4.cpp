#include <iostream>
#include <vector>
using namespace std;

// directions we check are (row-1, col), (row, col+1), (row+1, col), (row, col-1)
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int M, N; // m = Rows,  n =Colmn

// dfs
void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis) {
    vis[r][c] = 1;

    // 4 dircn
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i]; // new row
        int nc = c + dc[i]; // new colmn

        // conditions to check;
        // 1 Is it inside the grid
        // 2 Is it Land ('1')
        // 3 Is it unvisited
        if (nr >= 0 && nr < M && nc >= 0 && nc < N && 
            grid[nr][nc] == '1' && vis[nr][nc] == 0) {
            dfs(nr, nc, grid, vis);
        }
    }
}

int main() {
    M = 3; N = 3;
    vector<vector<char>> grid = {
        {'1', '1', '0'},
        {'0', '1', '0'},
        {'1', '0', '1'}
    };

    // vis array
    vector<vector<int>> vis(M, vector<int>(N, 0));

    int islands = 0;

    // OUTER LOOP: Iterate every cell
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            // when unvis
            if (grid[i][j] == '1' && vis[i][j] == 0) {
                islands++;
                dfs(i, j, grid, vis); // mark island
            }
        }
    }

    cout << islands << endl; // output is 3
    return 0;
}