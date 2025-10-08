#include <iostream>
using namespace std;

// Node structure
struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

// Insert node at end
void insert(Node*& head, int coeff, int pow) {
    Node* newNode = new Node(coeff, pow);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp = NULL;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) insert(result, sum, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            insert(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            insert(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1) {
        insert(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2) {
        insert(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Print polynomial
void printPolynomial(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->pow;
        if (poly->next) cout << " + ";
        poly = poly->next;
    }
    cout << endl;
}

// Driver code
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // First polynomial: 3x^3 + 5x^2 + 6
    insert(poly1, 3, 3);
    insert(poly1, 5, 2);
    insert(poly1, 6, 0);

    // Second polynomial: 6x^2 + 8x + 4
    insert(poly2, 6, 2);
    insert(poly2, 8, 1);
    insert(poly2, 4, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);

    cout << "Resultant Polynomial: ";
    printPolynomial(result);

    return 0;
}
