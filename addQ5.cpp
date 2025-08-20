#include <iostream>  //input 1 2 0 3 4 0 4 5  output 1 2 0 0 3 4 0 0 4
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
       int n= arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]==0){
                for(int j=n-1;j>i;j--){ //check 
                    arr[j]=arr[j-1]; //to shift right
                }
                i++;//skip duplicate zero
            }
        }
    }
};
int main(){

    return 0;
}