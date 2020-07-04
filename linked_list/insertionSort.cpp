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

void insert_node(node *&head, node *curr)
{

    if (head == NULL or head->data > curr->data)
    {
        curr->next = head;
        head = curr;
        return;
    }
    node *temp = head;
    node *prev;
    while (temp != NULL and curr->data > temp->data)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = curr;
    curr->next = temp;
}

node *insertion_sort(node *head)
{
    node *sorted = NULL;
    node *curr = head;
    node *next;
    while (curr != NULL)
    {
        next = curr->next;
        insert_node(sorted, curr);
        curr = next;
    }
    return sorted;
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

    head = insertion_sort(head);
    printList(head);
    return 0;
}