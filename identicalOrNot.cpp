#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

bool isSameTree(Node *p, Node *q)
{
    if (p == nullptr || q == nullptr)
    {
        return (p == q);
    }

    return (p->data == q->data) && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main()
{
    return 0;
}