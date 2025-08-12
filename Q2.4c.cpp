#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="cloud";
    string result=" ";
    for(int i=0; i<=str.length();i++){
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
            result+=str[i];
        }
    }
    cout<<"new word without vowels is "<<result;
    return 0;
}