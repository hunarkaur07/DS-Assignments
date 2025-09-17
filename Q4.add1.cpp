#include<iostream>
#include<string>
using namespace std;

string decToBin(int num){
    string binary= " ";
    while(num>0){
        binary = char((num%2)+'0')+binary;
        num=num/2; 
    }
    return binary;
}
void printBinary(int n){
    for(int i=1;i<=n;i++){
        cout<< decToBin(i) << " ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enter n ";
    cin>>n;
    printBinary(n);
    return 0;
}