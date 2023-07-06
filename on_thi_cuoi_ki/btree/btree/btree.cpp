#include <iostream>
#include <stack>
#include <vector>
using namespace std;


struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Hàm xuất btree 1
//Preorder traversal : Xuất theo thứ tự trước
void XuatBtree(Node* root)
{
    stack<Node*> stack;
    vector<int> result;

    stack.push(root);
    while (!stack.empty())
    {
        Node* node = stack.top();
        stack.pop();
        result.push_back(node->value);

        if (node->right)
            stack.push(node->right);
        if (node->left)
            stack.push(node->left);
    }

    for (int val : result)
        cout << val << " ";
    cout << endl;
}

void XuatBtreeInorder(Node* root)
{
    stack<Node*> stack;
    vector<int> result;

    Node* curr = root;
    while (curr != nullptr || !stack.empty())
    {
        while (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();
        result.push_back(curr->value);
        curr = curr->right;
    }

    for (int val : result)
        cout << val << " ";
    cout << endl;
}

void XuatBtreePostorder(Node* root)
{
    stack<Node*> stack;
    vector<int> result;

    Node* curr = root;
    Node* prev = nullptr;

    while (curr != nullptr || !stack.empty())
    {
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            Node* temp = stack.top();

            if (temp->right != nullptr && temp->right != prev)
            {
                curr = temp->right;
            }
            else
            {
                result.push_back(temp->value);
                stack.pop();
                prev = temp;
            }
        }
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";
    cout << endl;
}


void XuatBtreeReverseOrder(Node* root)
{
    stack<Node*> stack;
    vector<int> result;

    stack.push(root);
    while (!stack.empty())
    {
        Node* node = stack.top();
        stack.pop();
        result.push_back(node->value);

        if (node->left)
            stack.push(node->left);
        if (node->right)
            stack.push(node->right);
    }
    int i = 0;
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";
    cout << endl;
}

