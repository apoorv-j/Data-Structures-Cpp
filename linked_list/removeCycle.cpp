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

void removeCycle(node *&head)
{
    node *l1 = head;
    node *l2 = NULL;
    int counter = 0;
    while (l1->next != NULL)
    {
        counter++;
        l2 = l1->next;
        node *temp = head;
        for (int i = 0; i < counter; i++)
        {
            if (l2->data == temp->data)
            {
                l1->next = NULL;
                return;
            }
            temp = temp->next;
        }
        l1 = l1->next;
    }
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

    removeCycle(head);
    printList(head);

    return 0;
}