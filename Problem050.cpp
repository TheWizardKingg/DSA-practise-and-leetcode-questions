#include <iostream>
using namespace std;

struct Node {
    int coef, exp;
    Node* next;
    Node(int c, int e) : coef(c), exp(e), next(NULL) {}
};
void insert(Node*& head, int c, int e) {
    Node* temp = new Node(c, e);
    if (!head) head = temp;
    else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = temp;
    }
}
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            insert(result, p1->coef + p2->coef, p1->exp);
            p1 = p1->next; p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insert(result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else {
            insert(result, p2->coef, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1) { insert(result, p1->coef, p1->exp); p1 = p1->next; }
    while (p2) { insert(result, p2->coef, p2->exp); p2 = p2->next; }
    return result;
}
void display(Node* head) {
    while (head) {
        cout << head->coef << "x^" << head->exp;
        if (head->next) cout << " + ";
        head = head->next;
    }
}
int main() {
    Node *p1 = NULL, *p2 = NULL;
    insert(p1, 3, 2);
    insert(p1, 4, 1);
    insert(p1, 2, 0);
    insert(p2, 5, 1);
    insert(p2, 6, 0);
    Node* ans = addPoly(p1, p2);
    display(ans);
}
// i am being honest, this is the first and only time, i have copied code from GPT
//i know it already, and i am lazy, tired, in exam mode (i am going to say that everytime i can)
// and have no time at all, done these programs countless times before, so yeah..., i am not checking if this even works
//and again the golden words:- Who cares :)
