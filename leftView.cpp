#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

vector<int> lefttView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        Node *ele = node.first;
        int level = node.second;
        if (m.find(level) == m.end())
        {
            m[level] = ele->data;
        }

        if (ele->left)
        {
            q.push({ele->left, level + 1});
        }
        if (ele->right)
        {
            q.push({ele->right, level + 1});
        }
    }

    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    return 0;
}