#include <iostream>
#include <queue>
#include <unordered_map> //for frequency counting
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q; //to store characters in queue
    unordered_map<char, int> freq; //to store freq of each char

    for (char c : s) {
        freq[c]++;//inc freq of char
        q.push(c);//add to queue

        while (!q.empty() && freq[q.front()] > 1) {//q.front() gives the first element in the queue 
            q.pop();                               //freq[q.front()] > 1 checks the freq
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << "\n"; //prints non rep char d if space empty print -1
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    firstNonRepeating(str);
    return 0;
}

//using ASCII values

