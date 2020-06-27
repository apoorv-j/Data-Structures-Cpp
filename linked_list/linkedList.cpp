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

node *midpointOfList(node *slow, node *fast)
{
    if (fast == NULL or fast->next == NULL)
        return slow;

    return midpointOfList(slow->next, fast->next->next);
}

node *kthNodeFromEnd(node *head, int k)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    node *fast = head;
    while (k != 0)
    {
        fast = fast->next;
        k--;
    }
    node *slow = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

node *getMin(node *head1, node *head2)
{
    if (head1->data < head2->data)
        return head1;

    return head2;
}
node *mergeLists(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    node *head3;
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

node *mergeSort(node *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    node *mid = midpointOfList(head, head->next);

    node *head1 = mergeSort(mid->next);
    mid->next = NULL;
    node *head2 = mergeSort(head);
    head = mergeLists(head1, head2);
    return head;
}

bool detectCycle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

node *removeCycle(node *head)
{
    // Using floyd's algo
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    while (fast->next != slow)
    {
        fast = fast->next;
    }
    fast->next = NULL;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    node *head = NULL;
    node *head2 = NULL;

    cin >> head;
    // head = mergeSort(head);
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    node *start = head->next->next;
    temp->next = start;
    cout << boolalpha << detectCycle(head) << endl;
    head = removeCycle(head);
    cout << head;
    cout << boolalpha << detectCycle(head) << endl;

    return 0;
}