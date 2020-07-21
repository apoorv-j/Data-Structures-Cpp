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

pair<int, bool> checkBalance(node *root)
{
    if (root == NULL)
    {
        return make_pair(0, true);
    }

    pair<int, bool> lt = checkBalance(root->left);
    pair<int, bool> rt = checkBalance(root->right);

    if (abs(lt.first - rt.first) <= 1)
        return make_pair(max(lt.first, rt.first) + 1, true);
    else
        return make_pair(0, false);
}

int main()
{
    node *tree;
    tree = buildtree(tree);
    cout << boolalpha << checkBalance(tree).second;
    return 0;
}