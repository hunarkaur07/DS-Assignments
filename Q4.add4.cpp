#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int index = 0;   // points to top sandwich
    int rotations = 0;

    while (!q.empty() && rotations < q.size()) {
        if (q.front() == sandwiches[index]) {
            // student takes sandwich
            q.pop();
            index++;
            rotations = 0; // reset because we served someone
        } else {
            // student goes to back of queue
            q.push(q.front());
            q.pop();
            rotations++;
        }
    }
    return q.size(); // remaining students
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << countStudents(students, sandwiches) << endl;

    return 0;
}
