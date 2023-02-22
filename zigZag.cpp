#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

vector<vector<int>> zigzag(Node *root)
{
    vector<vector<int>> trav;
    queue<Node *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {

        int qsize = q.size();
        vector<int> row;
        for (int i = 0; i < qsize; i++)
        {
            Node *node = q.front();
            q.pop();
            row.push_back(node->data);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (flag == 0)
        {
            flag = 1;
        }
        else
        {
            reverse(row.begin(), row.end());
            flag = 0;
        }    
            trav.push_back(row);
      
    }
    return trav;
}
int main()
{
    return 0;
}