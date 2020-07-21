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
};

node *buildTreeUsingLevelOrder()
{
    int d;
    cin >> d;
    node *root = new node(d);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *f = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }
        if (c2 != -1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
    return root;
}
void printRightView(node *root, int level, int &maxlevel)
{
    // using dfs approach with right node first
    if (root == NULL)
        return;

    if (maxlevel < level)
    {
        cout << root->data << " ";
        maxlevel = level;
    }

    printRightView(root->right, level + 1, maxlevel);
    printRightView(root->left, level + 1, maxlevel);
}
void printLeftView(node *root, int level, int *maxlevel)
{
    // using dfs approach with right node first
    if (root == NULL)
        return;

    if (*maxlevel < level)
    {
        cout << root->data << " ";
        *maxlevel = level;
    }

    printLeftView(root->left, level + 1, maxlevel);
    printLeftView(root->right, level + 1, maxlevel);
}

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

int main()
{
    node *root = buildTreeUsingLevelOrder();
    // bfs(root);
    int temp = 0;
    printLeftView(root, 1, &temp);
    // printRightView(root, 0, temp);
    return 0;
}