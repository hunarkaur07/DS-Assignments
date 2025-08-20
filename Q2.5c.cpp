#include<iostream> //row major form 
using namespace std;

int main(){
    int arr[6]={1,2,3,4,5,6};
    int size=6;
    int n=0;
    while(n*(n+1)/2 <size){
        n++;
    }
    int index=0;
    cout<<"lower tri matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<=i){
                cout<<arr[index++]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return 0;
    
}