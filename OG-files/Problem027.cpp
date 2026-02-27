#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void push(Node*& top, int value) {
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}
void display(Node* top) {
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* top = NULL;
    int val;

    while (true) {
        cout << "Enter data (-1 to stop): ";
        cin >> val;

        if (val == -1) {
            break;
        }
        
        push(top, val);
    }

    int choice;
    cout << "1. DISPLAY\n2. EXIT\n";
    cin >> choice;

    if (choice == 1) {
        display(top);
    }

    return 0;
}
//implemented a stack using linked list
//provided options to push elements onto the stack and display the stack contents
//i will be adding cleaner code with classes later on in this repo