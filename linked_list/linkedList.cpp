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

void insertAtHead(node *&head, int data)
{
    node *new_node = new node(data);
    new_node->next = head;
    head = new_node;
}

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

int lengthOfList(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
void insertInMiddle(node *&head, int data, int index)
{
    node *new_node = new node(data);

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    if (index > lengthOfList(head))
    {
        insertAtTail(head, data);
        return;
    }

    node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
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

void deleteFromHead(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    head = head->next;
    delete temp;
}
void deleteFromTail(node *&head)
{
    if (head == NULL)
        return;
    node *prev;
    node *temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
}

void buildList(node *&head)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertAtTail(head, data);
        cin >> data;
    }
}

istream &operator>>(istream &is, node *&head)
{
    buildList(head);
    return is;
}

ostream &operator<<(ostream &os, node *&head)
{
    printList(head);
    return os;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    node *head = NULL;
    node *head2 = NULL;
    // for (int i = 0; i < 5; i++)
    // {
    //     insertAtHead(head, arr[i]);
    // }
    // printList(head);
    // insertInMiddle(head, 6, 2);
    // printList(head);
    // insertAtTail(head, 7);
    // printList(head);
    // deleteFromHead(head);
    // printList(head);
    // deleteFromTail(head);
    // printList(head);
    cin >> head >> head2;
    // buildList(head);
    cout << head << head2;
    // printList(head);
    return 0;
}