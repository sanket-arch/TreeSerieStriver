#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

vector<int> verticalTrav(Node *root)
{
    queue<pair<Node *, pair<int, int>>> q;
    // map will store unique
    // outer map will for verticals & inner for level and multiset will store the value at (vertical,level)
    // multiuset can have repeating value unlike set
    map<int, map<int, multiset<int>>> m;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        Node *ele = node.first;
        int vertical = node.second.first;
        int level = node.second.second;
        m[vertical][level].insert(ele->data);
        if (ele->left)
        {
            q.push({ele->left, {vertical - 1, level + 1}});
        }
        if (ele->right)
        {
            q.push({ele->right, {vertical + 1, level + 1}});
        }
    }
    vector<int> trav;
    for (auto it : m)
    {
        vector<int> col;
        for (auto itin : it.second)
        {
            col.insert(col.end(), itin.second.begin(), itin.second.end());
        }

        for (int p = 0; p < col.size(); p++)
        {
            trav.push_back(col[p]);
        }
    }
    return trav;
}

int main()
{
    return 0;
}