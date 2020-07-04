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

node *arrange(node *head)
{
    node *even = NULL;
    node *odd = NULL;
    node *odd_head = NULL,
         *even_head = NULL;
    node *head2 = head;
    int odd_flag = 0, even_flag = 0;
    while (head != NULL)
    {
        if ((head->data) % 2 != 0)
        {

            if (odd_flag == 0)
            {
                odd = head;
                odd_head = head;
                odd_flag = 1;
            }
            else
            {
                odd->next = head;
                odd = odd->next;
            }
        }
        else
        {
            // even->next = head;
            if (even_flag == 0)
            {
                even_head = head;
                even = head;
                even_flag = 1;
            }
            else
            {
                even->next = head;
                even = even->next;
            }
        }
        head = head->next;
    }

    if (odd_head == NULL or even_head == NULL)
        return head2;

    even->next = NULL;
    odd->next = even_head;

    return odd_head;
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

    head = arrange(head);
    printList(head);

    return 0;
}