
#include <iostream>
#include <stack>
using namespace std;

struct Student {
    int roll;
    string name;
    Student *left, *right;
};

// Insert student into BST
Student* insert(Student* root, int r, string n) {
    if (root == NULL) {
        Student* temp = new Student;
        temp->roll = r;
        temp->name = n;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (r < root->roll)
        root->left = insert(root->left, r, n);
    else
        root->right = insert(root->right, r, n);

    return root;
}

// Non-recursive Inorder
void inorder(Student* root) {
    stack<Student*> s;
    Student* p = root;

    while (p != NULL || !s.empty()) {
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }

        p = s.top();
        s.pop();

        cout << p->roll << " - " << p->name << endl;
        p = p->right;
    }
}

// Non-recursive Preorder
void preorder(Student* root) {
    if (root == NULL)
        return;

    stack<Student*> s;
    s.push(root);

    while (!s.empty()) {
        Student* p = s.top();
        s.pop();

        cout << p->roll << " - " << p->name << endl;

        if (p->right != NULL)
            s.push(p->right);

        if (p->left != NULL)
            s.push(p->left);
    }
}

int main() {
    Student* root = NULL;
    int n, r;
    string name;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter roll number and name: ";
        cin >> r >> name;
        root = insert(root, r, name);
    }

    cout << "\nInorder Traversal:\n";
    inorder(root);

    cout << "\nPreorder Traversal:\n";
    preorder(root);

    return 0;
}
