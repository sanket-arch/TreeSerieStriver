#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

bool getPath(Node *root, vector<int> &arr, int node)
{
    if (root == nullptr)
        return false;

    arr.push_back(root->data);
    if (root->data == node)
        return true;
    if (getPath(root->left, arr, node) || getPath(root->right, arr, node))
        return true;

    arr.pop_back();
    return false;
}

// Path to Leaf
bool isLeaf(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
        return true;

    else
        return false;
}

void pathToLeaf(Node *root, vector<int> arr, vector<string> &ans)
{
    if (root == nullptr)
        return;
    arr.push_back(root->data);

    if (isLeaf(root))
    {
        string s;
        for (auto it : arr)
        {
            s.append(to_string(arr[it]));
            if (it != arr.size() - 1)
                s.append("->");
        }
        ans.push_back(s);
        return;
    }
    pathToLeaf(root->left, arr, ans);
    pathToLeaf(root->right, arr, ans);
}
int main()
{
    return 0;
}