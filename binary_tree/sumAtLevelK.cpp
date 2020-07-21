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

node *buildTree()
{
    int data;
    cin >> data;
    node *root = new node(data);
    int c;
    cin >> c;
    while (c--)
    {
        if (c == 1)
            root->left = buildTree();
        else
            root->right = buildTree();
    }
    return root;
}

void getSumAtK(node *root, int level, int target, int &sum)
{
    if (root == NULL)
        return;
    if (level == target)
    {
        sum += root->data;
        return;
    }
    getSumAtK(root->left, level + 1, target, sum);
    getSumAtK(root->right, level + 1, target, sum);
}
int main()
{
    node *root = buildTree();
    int k;
    cin >> k;
    int sum = 0;
    getSumAtK(root, 0, k, sum);
    cout << sum;
    return 0;
}