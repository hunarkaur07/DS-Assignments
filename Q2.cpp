#include<iostream>
using namespace std;

void bubblesort(int n, int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[i]==arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={7, 2, 5, 3, 6, 4};
    int n=6;
    bubblesort(n, arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}