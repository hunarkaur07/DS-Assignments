// #include <iostream> //string split
// using namespace std;

// int main() {
//     string str;
//     cout << "Enter a sentence: ";
//     getline(cin, str);   // input with spaces

//     string word = "";
//     for (char c : str) {
//         if (c == ' ') {
//             cout << word << endl;
//             word = "";
//         } else {
//             word += c;
//         }
//     }
//     cout << word << endl; // print last word
//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Case 1: any char appears >= 3 times
    int freq[26] = {0};
    for (char c : s) {
        if (++freq[c - 'a'] >= 3) {
            cout << "YES";
            return 0;
        }
    }

    // Case 2: check simple splits
    for (int i = 1; i < n; i++) {
        string A = s.substr(0, i);
        string B = s.substr(i);
        if (B.find(A) != string::npos || A.find(B) != string::npos) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}

