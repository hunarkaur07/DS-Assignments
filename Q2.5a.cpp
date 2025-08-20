#include<iostream>
using namespace std;

int main(){
    int n=4;
    int arr[]={1,2,3,4};
    int k=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<arr[k++]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return 0;
}