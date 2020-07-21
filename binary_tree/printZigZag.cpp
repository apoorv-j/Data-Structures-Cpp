#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    // ~node();
};

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
void zigzag(node *root)
{
    deque<node *> odd, even;
    odd.push_back(root);
    while (!odd.empty() or !even.empty())
    {
        if (even.empty())
        {
            node *temp = odd.front();
            cout << temp->data << " ";
            odd.pop_front();
            if (temp->right != NULL)
                even.push_back(temp->right);
            if (temp->left != NULL)
                even.push_back(temp->left);
        }
        else
        {
            node *temp = even.front();
            cout << temp->data << " ";
            even.pop_front();
            if (temp->right != NULL)
                odd.push_front(temp->right);
            if (temp->left != NULL)
                odd.push_front(temp->left);
        }
    }
}

int x = 0;
node *buildtree(node *root)
{
    if (x == 0)
    {
        x++;
        int k;
        cin >> k;
        root = new node(k);
        root->left = buildtree(root->left);
        root->right = buildtree(root->right);
        return root;
    }
    else
    {
        string str;
        cin >> str;
        int d;
        if (str == "true")
        {
            cin >> d;
            node *temp = new node(d);
            temp->left = buildtree(temp->left);
            temp->right = buildtree(temp->right);
            return temp;
        }
        else if (str == "false")
        {
            return root;
        }
    }
    return root;
}

int main()
{
    node *tree;
    tree = buildtree(tree);
    // bfs(tree);
    // cout << endl;
    zigzag(tree);
    return 0;
}