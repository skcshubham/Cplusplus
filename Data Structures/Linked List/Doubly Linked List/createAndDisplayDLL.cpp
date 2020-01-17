#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

class linkedList
{
public:
    Node *head, *tail;
public:
    // constructor to initialize pointers to NULL at object creation
    linkedList()
    {
        head= tail= NULL;
    }

    // function to create a doubly linked list

    Node* createList(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->prev= NULL;
        temp->next= NULL;
        if(head == NULL)
        {
            head= tail= temp;
            head->prev= NULL;
            temp= NULL;
            return head;
        }
        else
        {
            tail->next= temp;
            temp->prev= tail;
            temp->next= NULL;
            tail= temp;
            return head;
        }
    } // end of createList() function

    // function to display a doubly linked list in ahead order ----->

    void displayForward(Node *head)
    {
        if(head == NULL)
            cout<<"Doubly Linked list is empty! "<<endl;
        else
        {
            Node *header= head;
            while(header != NULL)
            {
                cout<<header->data<<" -> ";
                header= header->next;
            }
            cout<<endl;
        }
    } // end of display() function

    // function to display a doubly linked list in backward order <-----

    void displayBackward(Node *tail)
    {
        if(tail == NULL)
            cout<<"Doubly Linked list is empty!"<<endl;
        else
        {
            Node *tailer= tail;

            // ( No need for this, we can use tail ptr to save computation time! O(n) time is saved. )

            //  while(tailer->next != NULL)
            // traversing to the end of DLL to display backward.
            //      tailer= tailer->next;


            // printing the doubly linked list backwards
            while(tailer != NULL)
            {
                cout<<tailer->data<<" -> ";
                tailer= tailer->prev;
            }
            cout<<endl;
        }
    } // end of display() function


};

int main()
{
    linkedList obj;
    int valueToBeInserted=0;

    // creating a doubly linked list

    cout<<"Enter the value that you want to insert in a doubly linked list: (Zero to end)"<<endl;
    cin>>valueToBeInserted;
    Node *list1= NULL;
    while(valueToBeInserted != 0)
    {
        list1= obj.createList(valueToBeInserted);
        cin>>valueToBeInserted;
    }

    // displaying a doubly linked list in frontal order

    cout<<"Doubly Linked in Forward Order: ";
    obj.displayForward(list1);

    // displaying a doubly linked list in backward order

    cout<<"Doubly Linked List in Backward Order: ";
    obj.displayBackward(obj.tail);

    return 0;
}
