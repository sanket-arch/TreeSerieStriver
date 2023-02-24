#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

bool isSymmetric(Node *root1, Node *root2)
{
    if (root1 == nullptr || root2 == nullptr)
        return true;
    if (root1->data != root2->data)
        return false;
    return isSymmetric(root1->left, root2->right) && (root1->right, root2->left);
}


int main()
{
    return 0;
}