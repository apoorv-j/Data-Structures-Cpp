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

node *buildTree()
{
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
node *buildTreeUsingLevelOrder()
{
    int d;
    cin >> d;
    node *root = new node(d);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int d1, d2;
        cin >> d1 >> d2;
        if (d1 != -1)
        {
            temp->left = new node(d1);
            q.push(root->left);
        }
        if (d2 != -1)
        {
            temp->right = new node(d2);
            q.push(root->right);
        }
    }
    return root;
}

void printPreOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void printInOrder(node *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}
void printPostOrder(node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int getHeight(node *root)
{
    if (root == NULL)
        return 0;

    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getDiameter(node *root)
{
    if (root == NULL)
        return 0;

    int l = getHeight(root->left);
    int r = getHeight(root->right);
    int h1 = l + r;
    int h2 = getDiameter(root->left);
    int h3 = getDiameter(root->right);
    return max(h1, max(h2, h3));
}

pair<int, int> getDiameterFast(node *root)
{
    pair<int, int> curr; //first->height and second->diameter
    if (root == NULL)
    {
        curr.first = curr.second = 0;
        return curr;
    }

    pair<int, int> left = getDiameterFast(root->left);
    pair<int, int> right = getDiameterFast(root->right);
    curr.first = max(left.first, right.first) + 1;

    curr.second = max(left.first + right.first, max(left.second, right.second));

    return curr;
}

void printCurrLevel(node *root, int height)
{
    if (root == NULL)
        return;
    if (height == 1)
    {
        cout << root->data << " ";
        return;
    }
    printCurrLevel(root->left, height - 1);
    printCurrLevel(root->right, height - 1);
}

void printAllLevels(node *root)
{
    int height = getHeight(root);

    for (int i = 1; i <= height; i++)
        printCurrLevel(root, i);
}

void printBFS(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
void printBFS2(node *root)
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

int countNodes(node *root)
{
    if (root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int totalSum(node *root)
{
    if (root == NULL)
        return 0;

    return totalSum(root->left) + totalSum(root->right) + root->data;
}

int replaceNodes(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
        return root->data;

    int l = replaceNodes(root->left);
    int r = replaceNodes(root->right);
    int curr = root->data;
    root->data = l + r;
    return root->data + curr;
}

pair<int, bool> checkHeightBalance(node *root)
{
    if (root == NULL)
        return make_pair(0, true);
    // if (root->left == NULL and root->right == NULL)
    //     return root->data;

    pair<int, bool> l = checkHeightBalance(root->left);
    pair<int, bool> r = checkHeightBalance(root->right);

    int h = max(l.first, r.first) + 1;
    if (abs(l.first - r.first) <= 1 and l.second and r.second)
        return make_pair(h, true);

    else
        return make_pair(h, false);
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
void printLeftView(node *root, int level, int &maxlevel)
{
    // using dfs approach with right node first
    if (root == NULL)
        return;

    if (maxlevel < level)
    {
        cout << root->data << " ";
        maxlevel = level;
    }

    printLeftView(root->left, level + 1, maxlevel);
    printLeftView(root->right, level + 1, maxlevel);
}

pair<int, int> maxSumPath(node *root)
{
    pair<int, int> p = make_pair(0, 0);
    if (root == NULL)
        return p;

    pair<int, int> lt = maxSumPath(root->left);
    pair<int, int> rt = maxSumPath(root->right);

    p.first = max(lt.first, max(rt.first, 0)) + root->data;

    int curr_max_sum = max(lt.first, max(rt.first, max(lt.first + rt.first, 0))) + root->data;

    p.second = max(curr_max_sum, max(lt.second, rt.second));

    return p;
}
pair<int, int> minSumPath(node *root)
{
    pair<int, int> p = make_pair(0, 0);
    if (root == NULL)
        return p;

    pair<int, int> lt = minSumPath(root->left);
    pair<int, int> rt = maxSumPath(root->right);

    p.first = min(lt.first, min(rt.first, 0)) + root->data;

    int curr_min_sum = min(lt.first, min(rt.first, min(lt.first + rt.first, 0))) + root->data;

    p.second = min(curr_min_sum, max(lt.second, rt.second));

    return p;
}

pair<int, bool> checkBST(node *root, int minv = INT_MIN, int maxv = INT_MAX)
{
    if (root == NULL)
        return make_pair(0, true);

    pair<int, bool> lt = checkBST(root->left, minv, root->data);
    pair<int, bool> rt = checkBST(root->right, root->data, maxv);

    if (root->data < maxv and root->data >= minv and lt.second and rt.second)
    {
        pair<int, bool> curr = make_pair(lt.first + rt.first + 1, true);
        cout << boolalpha << root->data << " " << lt.first << " " << lt.second << " " << rt.first << " " << rt.second << endl;
        return curr;
    }
    return make_pair(max(lt.first, rt.first), false);
}
void checkBST2(node *root, int &maxnodes)
{
    static int prev = INT_MIN;
    static int count = 0;

    if (root == NULL)
        return;

    checkBST2(root->left, maxnodes);

    if (root->data >= prev)
        count++;
    else
        count = 0;
    maxnodes = max(maxnodes, count);

    prev = root->data;

    checkBST2(root->right, maxnodes);
}
int getLargestBST(node *root)
{
    int maxnodes = 0;
    maxnodes = checkBST(root, INT_MIN, INT_MAX).first;
    // checkBST2(root, maxnodes);
    return maxnodes;
}

void printAtLevelK(node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
}

int printAtDistanceKfromTarget(node *root, int target, int k)
{
    if (root == NULL)
        return -1;

    if (root->data == target)
    {
        printAtLevelK(root, k);
        return 1;
    }

    int lt = printAtDistanceKfromTarget(root->left, target, k);

    if (lt != -1)
    {
        if (lt == k)
        {
            cout << root->data << " ";
            return lt;
        }
        else
        {
            printAtLevelK(root->right, k - lt - 1);
            return k - lt - 1;
        }
    }
    int rt = printAtDistanceKfromTarget(root->right, target, k);

    if (rt != -1)
    {
        if (rt == k)
        {
            cout << root->data << " ";
            return rt;
        }
        else
        {
            printAtLevelK(root->left, k - rt - 1);
            return k - rt - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int pre[n];
    int in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    node *tree = buildUsingPreOrder(pre, in, 0, n - 1);
    // printBFS2(tree);
    cout << getLargestBST(tree);
    return 0;
}