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
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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
}

Node *insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    
    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;  
    }
    
    while(temp != NULL && count < i-1){
        temp = temp -> next;
        count++;
    }

    //Method : 1
    if(temp != NULL){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    /*
    Method : 2
    if(temp != NULL){
        Node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    */
    return head;
}

int main()
{
    cout << "Linked List : " << endl;
    Node *head = takeInput();
    cout << "Linked List Before Insertion : " << endl;
    print(head);
    cout << endl << "Linked List After Insertion : " << endl;
    int i, data;
    cout << "Enter i and data" << endl;
    cin >> i >> data;
    head = insertNode(head, i, data);
    print(head);
    return 0;
}