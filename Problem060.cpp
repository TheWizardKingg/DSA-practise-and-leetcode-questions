#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Node* root = nullptr;
    for (int x : preorder) {
        root = insertBST(root, x);
    }

    cout << "Inorder traversal: ";
    inorder(root);
}
