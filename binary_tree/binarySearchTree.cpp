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

node *buildBST()
{
    int d;
    cin >> d;

    node *root = NULL;
    while (d != -1)
    {
        insertInBST(root, d);
        cin >> d;
    }
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

bool search(node *root, int data)
{
    if (root == NULL)
        return false;

    if (root->data == data)
        return true;

    if (data <= root->data)
        return search(root->left, data);

    return search(root->right, data);
}

node *deleteNode(node *root, int data)
{
    if (root == NULL)
        return root;

    else if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        // 1. leaf node
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 2. left child only
        else if (root->left != NULL and root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        //3. right child only
        else if (root->right != NULL and root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        //4.both children present
        else
        {
            //find min value child from right, replace root data with that, delete that child node
            node *child = root->right;
            while (child->left != NULL)
            {
                child = child->left;
            }
            root->data = child->data;
            root->right = deleteNode(root->right, child->data);
        }
    }
    return root;
}

bool checkBST(node *root, int minv = INT_MIN, int maxv = INT_MAX)
{
    if (root == NULL)
        return true;

    if (root->data < maxv and root->data >= minv and checkBST(root->left, minv, root->data) and checkBST(root->right, root->data, maxv))
        return true;

    return false;
}

class Pair
{
public:
    node *head;
    node *tail;
    Pair()
    {
        head = NULL;
        tail = NULL;
    }
};

Pair flattenBST(node *root)
{
    Pair p;
    if (root == NULL)
        return p;

    Pair left = flattenBST(root->left);
    Pair right = flattenBST(root->right);

    // 1. both left and right are NULL
    if (left.head == NULL and right.head == NULL)
    {
        p.head = p.tail = root;
    }

    // 2. only left tree
    else if (left.head != NULL and right.head == NULL)
    {
        left.tail->right = root;
        p.head = left.head;
        p.tail = root;
    }

    // 3. only right tree
    else if (left.head == NULL and right.head != NULL)
    {
        root->right = right.head;
        p.head = root;
        p.tail = right.tail;
    }

    // 4.both left and right are present
    else
    {
        left.tail->right = root;
        root->right = right.head;

        p.head = left.head;
        p.tail = right.tail;
    }

    return p;
}

int findGreaterElement(int *arr, int s, int n, int ele)
{
    for (int i = s; i < n; i++)
    {
        if (arr[i] > ele)
            return i;
    }
    return n;
}

node *buildUsingPreorder(int *arr, int i, int n)
{
    if (i == n)
        return NULL;

    node *root = new node(arr[i]);
    int right = findGreaterElement(arr, i, n, root->data);

    root->left = buildUsingPreorder(arr, i + 1, right);
    root->right = buildUsingPreorder(arr, right, n);

    return root;
}

node *buildUsingInorder(int *arr, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;

    node *root = new node(arr[mid]);
    root->left = buildUsingInorder(arr, s, mid - 1);
    root->right = buildUsingInorder(arr, mid + 1, e);

    return root;
}

void update(node *root, int &sum)
{
    if (root == NULL)
        return;

    update(root->right, sum);
    sum += root->data;
    root->data = sum;
    update(root->left, sum);
}
void printPreOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
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
        node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            insertInBST(root, x);
        }
        // bfs(root);
        int k;
        cin >> k;
        while (k--)
        {
            int del;
            cin >> del;
            root = deleteNode(root, del);
        }
        printPreOrder(root);
        cout << endl;
    }
    return 0;
}