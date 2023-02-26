#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
void markParent(Node *root, unordered_map<Node *, Node *> &parents)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
            parents[node->left] = node;
        }

        if (node->right)
        {
            q.push(node->right);
            parents[node->right] = node;
        }
    }
}

vector<int> distance(Node *root, Node *node, int k)
{
    unordered_map<Node *, bool> visited;
    unordered_map<Node *, Node *> parents;
    queue<Node *> q;
    markParent(root, parents);
    int dist = 0;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int qsize = q.size();
        if (dist++ == k)
            break;
        for (int i = 0; i < qsize; i++)
        {
            Node *curr_node = q.front();
            q.pop();
            if (curr_node->left && !visited[curr_node->left])
            {
                q.push(curr_node->left);
                visited[curr_node->left] = true;
            }
            if (curr_node->right && !visited[curr_node->right])
            {
                q.push(curr_node->right);
                visited[curr_node->right] = true;
            }
            if (parents[curr_node] && !visited[parents[curr_node]])
            {
                q.push(parents[curr_node]);
                visited[parents[curr_node]] = true;
            }
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}

int main()
{
    return 0;
}