#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *LCA(Node *root, Node *node1, Node *node2)
{
    if (root == nullptr || root == node1 || root == node2)
        return root;
    Node *left = LCA(root->left, node1, node2);
    Node *right = LCA(root->right, node1, node2);
    if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    else
        return root;
}

int main()
{
    return 0;
}