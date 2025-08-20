#include<iostream>
#include<string>
using namespace std;

int main(){
    char s1[]="hello ";
    char s2[]="world";
    strcat(s1,s2);
    cout<<"new string is "<<s1;
    return 0;
}
