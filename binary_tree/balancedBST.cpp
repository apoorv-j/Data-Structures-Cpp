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

void printPreOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
node *buildBalancedTree(int *arr, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildBalancedTree(arr, s, mid - 1);
    root->right = buildBalancedTree(arr, mid + 1, e);

    return root;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        node *root = buildBalancedTree(arr, 0, n - 1);
        printPreOrder(root);
        cout << endl;
    }

    return 0;
}