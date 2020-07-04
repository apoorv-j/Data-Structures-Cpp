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

int kthElement(node *head, int k)
{
    node *fast = head;
    node *slow = head;
    while (k-- > 0)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

int main()
{
    node *head = NULL;

    int data;
    cin >> data;
    while (data != -1)
    {
        insertAtTail(head, data);
        cin >> data;
    }
    int k;
    cin >> k;
    cout << kthElement(head, k);

    return 0;
}