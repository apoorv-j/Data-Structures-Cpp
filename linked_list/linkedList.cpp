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

void reverseLinkedList(node *&head)
{
    node *prev = NULL;
    node *temp;
    while (temp != NULL)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    head = prev;
}

node *recursiveReverse(node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    node *new_head = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}
// void reverse(node *prev, node *&head)
// {

//     if (head->next == NULL)
//     {
//         head->next = prev;
//         cout << "head : " << head;
//         return;
//     }

//     node *c = head;
//     reverse(head, head->next);
//     c->next = prev;
//     prev->next = NULL;
//     cout << "head : " << head;
//     cout << "prev : " << prev;
//     cout << "curr : " << c << endl;
// }

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    node *head = NULL;
    node *head2 = NULL;

    // cin >> head >> head2;
    // // buildList(head);
    // cout << head << head2;
    // printList(head);

    for (int i = 0; i < 5; i++)
    {
        insertAtHead(head, arr[i]);
    }
    cout << head;
    // reverseLinkedList(head);
    head = recursiveReverse(head);
    cout << head;

    // reverse(head, head);
    // cout << head;

    return 0;
}