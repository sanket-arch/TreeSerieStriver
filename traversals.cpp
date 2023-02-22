#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

vector<int> preorder(Node *root)
{
    stack<Node *> stk;
    stk.push(root);
    vector<int> pre;
    while (!stk.empty())
    {
        Node *ele = new Node;
        ele = stk.top();
        pre.push_back(ele->data);
        if (ele->right != nullptr)
            stk.push(ele->right);
        if (ele->left != nullptr)
            stk.push(ele->left);
    }
    return pre;
}

vector<int> Inorder(Node *root)
{
    stack<Node *> stk;
    Node *node = root;
    vector<int> inorder;
    do
    {
        if (node != nullptr)
        {
            stk.push(node);
            node = node->left;
        }
        else
        {
            node = stk.top();
            stk.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    } while (!stk.empty());

    return inorder;
}

vector<int> postOrderUsing2Stack(Node *root)
{
    stack<Node *> stk1, stk2;
    vector<int> post;
    stk1.push(root);
    while (!stk1.empty())
    {
        root = stk1.top();
        stk1.pop();
        stk2.push(root);
        if (root->left != nullptr)
            stk1.push(root->left);
        if (root->right != nullptr)
            stk1.push(root->right);
    }
    while (!stk2.empty())
    {
        post.push_back(stk2.top()->data);
        stk2.pop();
    }
    return post;
}
vector<int> postOrderUsing1Stack(Node *root)
{
    stack<Node *> stk;
    vector<int> post;
    stk.push(root);
    while (root != nullptr || !stk.empty())
    {
        if (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }
        else
        {
            Node *temp = stk.top()->right;
            if (temp == nullptr)
            {
                temp = stk.top();
                stk.pop();
                post.push_back(temp->data);
                while (!stk.empty() && temp == stk.top()->right)
                {
                    temp = stk.top();
                    stk.pop();
                    post.push_back(temp->data);
                }
            }
            else
            {
                root = temp;
            }
        }
    }
}

void allInOne(Node *root)
{
    stack<Node *, int> stk;
    stk.push(make_pair(root, 1));
    vector<int> pre, in, post;
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            stk.push(it);
            if (it.first->left != nullptr)
            {
                stk.push(make_pair(it.first->left, 1));
            }
        }
        if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            stk.push(it);
            if (it.first->right != nullptr)
            {
                stk.push(make_pair(it.first->right, 1));
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
}
int main()
{
    return 0;
}