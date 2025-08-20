//sort in terms of 0 ,1 ,2 
#include <iostream>
#include <algorithm>
using namespace std;

void sortArr(int arr[], int n){
    sort(arr, arr + n);
}

int main(){
    int arr[]={0,1,2,0,1,2};
    int n=6;
    cout<<"og array ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sortArr(arr,n);
    cout<<"sorted array ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}