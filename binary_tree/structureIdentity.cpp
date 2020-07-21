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

bool checkStructureIdentity(node *a, node *b)
{
    //both are null
    if (a == NULL and b == NULL)
        return true;

    //both are not null then check for their childs
    if (a != NULL and b != NULL)
    {
        return checkStructureIdentity(a->left, b->left) and checkStructureIdentity(a->right, b->right);
    }

    // only one of them is null
    return false;
}

int main()
{
    node *tree1, *tree2;
    tree1 = buildtree(tree1);
    x = 0;
    tree2 = buildtree(tree2);
    // bfs(tree1);
    // cout << endl;
    // bfs(tree2);
    cout << boolalpha << checkStructureIdentity(tree1, tree2);
    return 0;
}