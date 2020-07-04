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

node *reverse(node *head)
{
    if (head->next == NULL)
        return head;

    node *new_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

bool isPalindrome(node *head)
{
    node *rl = reverse(head);
    while (head != NULL)
    {
        if (head->data != rl->data)
            return false;

        head = head->next;
        rl = rl->next;
    }
    return true;
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

    cout << boolalpha << isPalindrome(head);

    return 0;
}