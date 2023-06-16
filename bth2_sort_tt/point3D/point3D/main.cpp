#include <iostream>

using namespace std;

struct Point {
    int x, y, z;
};

struct Node {
    Point point;
    Node* left;
    Node* right;
};

void insert(Node*& root, Point point) {
    if (root == nullptr) {
        root = new Node;
        root->point = point;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (point.x < root->point.x) {
        insert(root->left, point);
    }
    else if (point.x > root->point.x) {
        insert(root->right, point);
    }
    else if (point.y > root->point.y) {
        insert(root->left, point);
    }
    else if (point.y < root->point.y) {
        insert(root->right, point);
    }
    else if (point.z < root->point.z) {
        insert(root->left, point);
    }
    else {
        insert(root->right, point);
    }
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->point.x << " " << root->point.y << " " << root->point.z << endl;
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        Point point;
        cin >> point.x >> point.y >> point.z;
        insert(root, point);
    }
    inorder(root);
    return 0;
}