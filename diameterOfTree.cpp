#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
int height(Node *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);
    maxi = max(maxi, 1 + lh + rh);
    return 1 + max(lh, rh);
}
int diameter(Node *root)
{
    int maxi = 0;
    height(root, maxi);
    return maxi;
}
int main()
{
    return 0;
}