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
node *buildUsingPreOrder(int *pre, int *in, int s, int e)
{
    static int itr = 0;
    if (s > e)
        return NULL;

    int temp = pre[itr++];
    int r = find(in + s, in + e, temp) - in;

    node *root = new node(temp);
    root->left = buildUsingPreOrder(pre, in, s, r - 1);
    root->right = buildUsingPreOrder(pre, in, r + 1, e);

    return root;
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

void print(node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL)
        cout << "END";
    else
        cout << root->left->data;

    cout << " => " << root->data << " <= ";

    if (root->right == NULL)
        cout << "END";
    else
        cout << root->right->data;
    cout << endl;
    print(root->left);
    print(root->right);
}
int main()
{
    int n;
    cin >> n;
    int pre[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    int x;
    cin >> x;
    int in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    node *root = buildUsingPreOrder(pre, in, 0, n - 1);
    // bfs(root);
    print(root);
    return 0;
}