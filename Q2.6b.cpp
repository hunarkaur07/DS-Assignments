#include <iostream>
using namespace std;

int main() {
    int m, n, t1, t2;
    cout << "Enter rows, columns, non-zero elements of first matrix: ";
    cin >> m >> n >> t1;

    int A[t1+1][3];
    A[0][0] = m; A[0][1] = n; A[0][2] = t1;

    cout << "Enter row, column, value for each non-zero element:\n";
    for(int i = 1; i <= t1; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];


    cout << "Enter non-zero elements of second matrix: ";
    cin >> t2;
    int B[t2+1][3];
    B[0][0] = m; B[0][1] = n; B[0][2] = t2;

    for(int i = 1; i <= t2; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    int C[t1+t2+1][3];
    C[0][0] = m; C[0][1] = n;
    int i=1, j=1, k=1;

    while(i <= t1 && j <= t2) {
        if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1]))
            C[k][0]=A[i][0], C[k][1]=A[i][1], C[k++][2]=A[i++][2];
        else if(A[i][0]>B[j][0] || (A[i][0]==B[j][0] && A[i][1]>B[j][1]))
            C[k][0]=B[j][0], C[k][1]=B[j][1], C[k++][2]=B[j++][2];
        else
            C[k][0]=A[i][0], C[k][1]=A[i][1], C[k++][2]=A[i++][2]+B[j++][2];
    }

    while(i <= t1) C[k][0]=A[i][0], C[k][1]=A[i][1], C[k++][2]=A[i++][2];
    while(j <= t2) C[k][0]=B[j][0], C[k][1]=B[j][1], C[k++][2]=B[j++][2];

    C[0][2] = k-1;

    cout << "Resultant sparse matrix:\n";
    for(int p=0; p<k; p++)
        cout << C[p][0]<<" "<<C[p][1]<<" "<<C[p][2]<<endl;

    return 0;
}

