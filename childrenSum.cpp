#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int childrenSum(Node *root)
{
    if (root == nullptr)
        return 0;
    int childValue = 0;
    if (root->left)
        childValue += root->left->data;
    if (root->right)
        childValue += root->right->data;
    if (root->data > childValue)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    else
    {
        root->data = root->left->data + root->right->data;
    }
    int leftValue = childrenSum(root->left);
    int rightValue = childrenSum(root->right);

    if (root->data < leftValue + rightValue)
        root->data = leftValue + rightValue;
    return root->data;
}
int main()
{
    return 0;
}
