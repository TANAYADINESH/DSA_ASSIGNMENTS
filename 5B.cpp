
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    Student *left, *right;

    Student(int r, string n) {
        roll = r;
        name = n;
        left = right = NULL;
    }
};

// Non-recursive insertion in BST
Student* insert(Student* root, int roll, string name) {
    Student* newNode = new Student(roll, name);

    if (root == NULL)
        return newNode;

    Student* current = root;
    Student* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (roll < current->roll)
            current = current->left;
        else if (roll > current->roll)
            current = current->right;
        else {
            cout << "Duplicate roll number not allowed!\n";
            delete newNode;
            return root;
        }
    }

    if (roll < parent->roll)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Non-recursive Inorder Traversal
void inorder(Student* root) {
    stack<Student*> s;
    Student* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->roll << " - "
             << current->name << endl;

        current = current->right;
    }
}

// Non-recursive Preorder Traversal
void preorder(Student* root) {
    if (root == NULL)
        return;

    stack<Student*> s;
    s.push(root);

    while (!s.empty()) {
        Student* current = s.top();
        s.pop();

        cout << current->roll << " - "
             << current->name << endl;

        if (current->right != NULL)
            s.push(current->right);

        if (current->left != NULL)
            s.push(current->left);
    }
}

int main() {
    Student* root = NULL;
    int n, roll;
    string name;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students!";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter roll number and name: ";
        cin >> roll >> name;

        root = insert(root, roll, name);
    }

    cout << "\nInorder Traversal:\n";
    inorder(root);

    cout << "\nPreorder Traversal:\n";
    preorder(root);

    return 0;
}
