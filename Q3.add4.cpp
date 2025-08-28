#include <iostream>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0); //default 0 that means no warmer day

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && !ans[i]; j++) { //answer found, stop
            if (temp[j] > temp[i]) ans[i] = j - i;
        }
    }
    return ans;
}

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    for (int d : dailyTemperatures(temp)) cout << d << " ";
    return 0;
}
