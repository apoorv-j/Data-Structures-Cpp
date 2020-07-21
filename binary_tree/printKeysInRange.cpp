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
void insertInBST(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
    }
    else
    {
        if (data <= root->data)
        {
            insertInBST(root->left, data);
        }
        else
        {
            insertInBST(root->right, data);
        }
    }
}

void printPreOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void nodesInRange(node *root, int a, int b)
{
    if (root == NULL)
        return;

    int rd = root->data;

    if (rd > a)
        nodesInRange(root->left, a, b);
    if (rd >= a and rd <= b)
    {
        cout << rd << " ";
    }
    if (rd < b)
        nodesInRange(root->right, a, b);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int data;
        node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            insertInBST(root, data);
        }
        int a, b;
        cin >> a >> b;
        cout << "# Preorder : ";
        printPreOrder(root);
        cout << "\n# Nodes within range are : ";
        nodesInRange(root, a, b);
        cout << endl;
    }

    return 0;
}