#include<iostream>
#include<string>
using namespace std;

int main(){
    string str ="hunar";
    for(int i=str.length()-1;i>=0;i--){
        cout<<str[i];
    }
    return 0;
}