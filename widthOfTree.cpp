#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int width(Node *root)
{
    queue<pair<Node *, int>> q;
    int ans = 0;
    if (root == nullptr)
        return ans;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int levelMin = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            auto ele = q.front();
            q.pop();
            int curr_id = ele.second - levelMin;
            Node *node = ele.first;
            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;
            if (node->left)
                q.push({node->left, curr_id * 2 + 1});
            if (node->right)
                q.push({node->right, curr_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    return 0;
}