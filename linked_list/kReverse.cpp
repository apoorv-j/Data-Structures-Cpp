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

void kReverse(node *&head, int k)
{
    for (int i = 0; i < k; i++)
    {
    }
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
    kReverse(head, k);
    printList(head);
    return 0;
}