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

node *mergeLists(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    node *head3 = NULL;
    if (head1->data < head2->data)
    {
        head3 = head1;
        head3->next = mergeLists(head1->next, head2);
    }
    else
    {
        head3 = head2;
        head3->next = mergeLists(head1, head2->next);
    }
    return head3;
}

int main()
{

    int t;
    cin >> t;
    while (t-- > 0)
    {
        node *head = NULL;
        node *head2 = NULL;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            insertAtTail(head, data);
        }
        int n2;
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            int data;
            cin >> data;
            insertAtTail(head2, data);
        }
        head = mergeLists(head, head2);
        printList(head);
    }
    return 0;
}