#include<iostream>
using namespace std;

int main(){
    char ch = 'H';
    if (ch >= 'A' && ch <= 'Z')  
        ch = ch + 32;            
    cout << "Lowercase: " << ch;
    return 0;
}