#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int data;
    cout << "Enter data (-1 for no node): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree();

    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

// Just to verify your tree isn’t imaginary
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    root = buildTree();

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
