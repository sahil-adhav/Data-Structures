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

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (M == 0 || head == NULL)
    {
        return NULL;
    }

    if (N == 0)
    {
        return head;
    }

    Node *currNode = head;
    Node *temp = NULL;

    while (currNode != NULL)
    {
        int take = 0;
        int skip = 0;

        while (currNode != NULL && take < M)
        {
            if (temp == NULL)
            {
                temp = currNode;
            }
            else
            {
                temp->next = currNode;
                temp = currNode;
            }
            currNode = currNode->next;
            take++;
        }

        while (currNode != NULL && skip < N)
        {
            Node *newNode = currNode;
            delete currNode;
            currNode = newNode->next;
            skip++;
        }
    }

    if (temp != NULL)
    {
        temp->next = NULL;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}