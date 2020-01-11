#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class linkedList
{
public: // I've made this public so that recursiveReverseLIst() can access the head of my function when it's called in main()
    Node *head, *tail;
public:
    // constructor to initialize the head and tail to NULL
    linkedList()
    {
        head= tail= NULL;
    }

    // function to create a singly linked list

    void createList(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        // if the linked list is empty and contains no nodes
        if(head == NULL)
        {
            head= tail= temp;
            temp= NULL;
        }
        // if the linked list isn't empty and contains more than 1 nodes
        else
        {
            tail->link= temp;
            tail= temp;
            temp= NULL;
        }
    } // end of createList() function

    // function to display the linked list

    void display()
    {
        Node *temp= head;
        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp= temp->link;
        }
        cout<<"\n\n";
    } // end of display() function

    // function to reverse the singly linked list

    void reverseList()
    {
        Node *current= head, *pre= NULL, *prePre= NULL;
        while(current != NULL)
        {
            // sliding the 3 pointers, one node at a time
            prePre= pre;
            pre= current;
            current= current->link;
            // reversing the link to the previous node
            pre->link= prePre;
        }
        head= pre;
    } // end of reverseList() function

    void recursiveReverseList(Node *prev, Node *current)
    {
        /* in recursive reversing, we first traverse the node till the end using two sliding pointers and then
            reverse the links while we pop the stacks created or while returning back of the recursive call.
            (It's really one of the most beautiful code I've ever written !!)
        */
        // until the current pointer points to null
        if(current != NULL)
        {
            // traversing the linked list using the two sliding pointers (we're making a recursive call here)
            recursiveReverseList(current, current->link);
            // reversing the links while we're returning from recursive call (popping those stacks)
            current->link= prev; // if you're confused about it, refer RBR DS
        }
        // if the current pointer goes beyond the end of the list (when current == NULL) then prev points to last node which'll be our new head
        else
        {
            head= prev;
        }
    }
};

int main()
{
    linkedList obj;
    int valueToBeInserted=0;
    cout<<"Insert Value to be inserted in Linked List(Zero to end list) :\n";
    cin>>valueToBeInserted;
    while(valueToBeInserted != 0)
    {
        obj.createList(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"Linked List before reversing: ";
    obj.display();
    cout<<"Linked List after reversing using iterative method using 3 sliding pointers: ";
    obj.reverseList();
    obj.display();
    cout<<"Linked list after reversing using recursive method using 2 sliding pointers: ";
    obj.recursiveReverseList(NULL, obj.head);
    obj.display();
    return 0;
}
