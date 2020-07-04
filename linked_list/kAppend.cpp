#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(node *&head, int data)
{
    node *new_node = new node(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *kAppend(node *head, int n, int k)
{
    if (k >= n)
        k = k % n;

    if (k < 1)
        return head;

    node *temp = head;
    int count = 0;

    while (count++ < n - k - 1)
    {
        temp = temp->next;
    }
    node *end = temp;

    node *head2 = temp->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    end->next = NULL;
    temp->next = head;
    return head2;
}

int main()
{
    node *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insertAtTail(head, data);
    }
    int k;
    cin >> k;
    head = kAppend(head, n, k);
    printList(head);

    return 0;
}