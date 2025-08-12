#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int n=5;

    int t;
    cout<<"enter num to find ";
    cin>>t;

    int start=0;
    int end=n-1;
    int mid;

    while(start<=end){
        mid=(start+end)/2;

        if(arr[mid]==t){
            cout<<"found at index "<<mid<<endl;
            break;
        } 
        else if(arr[mid]<t){   //search in the right half
            start=mid+1;
        }
        else{
            end=mid-1;   //left half
        }
    }

    return 0;
}