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

node *kReverse(node *head, int k)
{

    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    int count = 0;

    while (curr != NULL and count++ < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if (next != NULL)
        head->next = kReverse(next, k);

    return prev;
}
int main()
{
    node *head = NULL;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insertAtTail(head, data);
    }
    head = kReverse(head, k);
    printList(head);
    return 0;
}