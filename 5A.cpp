
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Non-Recursive Inorder Traversal
// Left -> Root -> Right
void inorder(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        cout << current->data << " ";

        current = current->right;
    }
}

// Non-Recursive Preorder Traversal
// Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL)
        return;

    Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        Node* current = stack[top--];

        cout << current->data << " ";

        if (current->right != NULL)
            stack[++top] = current->right;

        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

int main() {
    // Creating Binary Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    return 0;
}
