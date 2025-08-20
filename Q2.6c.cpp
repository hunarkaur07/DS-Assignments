#include <iostream>
using namespace std;

int main() {
    //matrix 1
    int m1, n1, t1, m2, n2, t2;
    cout << "Enter rows, columns, non-zero elements of first matrix: ";
    cin >> m1 >> n1 >> t1;
    int A[t1+1][3];
    A[0][0]=m1; //no of rows
    A[0][1]=n1; //cols
    A[0][2]=t1; //non zero elements
    for(int i=1;i<=t1;i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    //matrix 2
    cout << "Enter rows, columns, non-zero elements of second matrix: ";
    cin >> m2 >> n2 >> t2;
    if(n1 != m2){ 
        cout<<"Multiplication not possible\n"; 
        return 0;
    }
    int B[t2+1][3];
    B[0][0]=m2; 
    B[0][1]=n2; 
    B[0][2]=t2;
    for(int i=1;i<=t2;i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }


    int C[1000][3]; // max non-zero elements
    int k=1;
    for(int i=1;i<=t1;i++){
        for(int j=1;j<=t2;j++){
            if(A[i][1]==B[j][0]){
                int found=0;
                for(int p=1;p<k;p++){
                    if(C[p][0]==A[i][0] && C[p][1]==B[j][1]){ 
                        C[p][2]+=A[i][2]*B[j][2]; found=1; break;
                    }
                }
                if(!found) C[k][0]=A[i][0], C[k][1]=B[j][1], C[k][2]=A[i][2]*B[j][2], k++;
            }
        }
    }
    C[0][0]=m1; C[0][1]=n2; C[0][2]=k-1;

    cout << "Resultant sparse matrix:\n";
    for(int p=0;p<k;p++) cout << C[p][0]<<" "<<C[p][1]<<" "<<C[p][2]<<endl;

    return 0;
}
