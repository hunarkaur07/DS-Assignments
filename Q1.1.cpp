#include <iostream>
using namespace std;

int arr[100]; // global array
int n = 0;    // number of elements

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    int pos, val;
    cout << "Enter position (0-based index) and value: ";
    cin >> pos >> val;
    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position (0-based index) to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch() {
    int key, found = 0;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "Element not found" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}
