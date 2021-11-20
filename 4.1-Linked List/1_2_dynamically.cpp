#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; //this will store address of next element

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;  //creating temp variable so that we dont loose head.
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    Node *n1 = new Node(1);
    Node *head = n1; // Here we are storing address of n1 so we dont
                      //loose it.
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    n1 -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;

    print(head);    //Passing only head will print all node.
    return 0;
}