#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
int maxSum(Node *node, int &maxi)
{
    if (node == nullptr)
        return 0;
    int leftSum = max(0, maxSum(node->left, maxi));
    int rightSum = max(0, maxSum(node->right, maxi));
    maxi = max(maxi, (leftSum + rightSum + node->data));
    return node->data + max(leftSum, rightSum);
}

int main()
{
    return 0;
}