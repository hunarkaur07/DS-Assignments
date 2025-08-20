#include<iostream>
using namespace std;

int findmissing(int arr[],int n){
    int low =0, high =n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]!= mid+1 && arr[mid-1]==mid){
            return (mid +1);
        }
        else if (arr[mid]== mid+1){
            low= mid+1;
        }
        else{
            high=mid-1;
        }
    }
<<<<<<< HEAD
    return 1;
=======
    return -1;
>>>>>>> c9b063cb346804d13114fa56f86635cf20344d2d
}

int main(){
    int arr[5]={1,2,3,5,6};
    cout<<"missing num is "<<findmissing(arr,5);

    return 0;
}