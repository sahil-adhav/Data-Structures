#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *findMid(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeTwoLL(Node *half1, Node *half2)
{
    Node *head = NULL, *tail = NULL;
    if (half1 == NULL)
    {
        return half2;
    }

    if (half2 == NULL)
    {
        return half1;
    }

    if (half1->data < half2->data)
    {
        head = half1;
        tail = half1;
        half1 = half1->next;
    }
    else
    {
        head = half2;
        tail = half2;
        half2 = half2->next;
    }

    while (half1 != NULL && half2 != NULL)
    {
        if (half1->data < half2->data)
        {
            tail->next = half1;
            tail = tail->next;
            half1 = half1->next;
        }
        else
        {
            tail->next = half2;
            tail = tail->next;
            half2 = half2->next;
        }
    }

    if (half1 != NULL)
    {
        tail->next = half1;
    }

    if (half2 != NULL)
    {
        tail->next = half2;
    }

    return head;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *half1, *half2;
    Node *mid = findMid(head);
    half1 = head;
    half2 = mid->next;
    mid->next = NULL;
    half1 = mergeSort(half1);
    half2 = mergeSort(half2);
    Node *finalHead = mergeTwoLL(half1, half2);
    return finalHead;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = mergeSort(head);
        print(head);
    }
    return 0;
}