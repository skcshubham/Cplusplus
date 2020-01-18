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
private:
    Node *head, *tail;
public:
    // constructor function to initialize member variables
    linkedList()
    {
        head= tail= NULL;
    }

    // function to display Doubly Linked List

    void createList(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->prev= temp->next= NULL;
        // if linked list is empty
        if(head == NULL)
        {
            head= tail= temp;
            head->prev= NULL;
            temp= NULL;
        }
        // if DLL has nodes
        else
        {
            tail->next= temp;
            temp->prev= tail;
            temp->next= NULL;
            tail= temp;
        }
    } // end of createList() function

    // function to display DLL

    void display()
    {
        Node *header= head;
        while(header != NULL)
        {
            cout<<header->data<<" <=> ";
            header= header->next;
        }
        cout<<endl;
    } // end of display() function

    // function to reverse the doubly linked list

    /* It's very simple to reverse a doubly linked list. We just traverse the DLL using a pointer until it encounters NULL
       and we change the next value to prev value and prev value to next value for each node in the DLL and that leads to
       reverse doubly linked list.
    */

    void reverseList()
    {
        // temp pointer act acts 3rd variable for swapping the next and prev value in a node to reverse the list.
        Node *temp= new Node;
        // another temp holds the head value so that it get swapped with tail at the end.
        Node *anotherTemp= head;
        // header is used to traverse the DLL
        Node *header= head;
        while(header != NULL)
        {
            // swapping the prev and next pointer using temp as 3rd variable
            temp= header->next;
            header->next= header->prev;
            header->prev= temp;
            // reassigning temp value to NULL
            temp= NULL;
            // moving header to one node ahead but as the pointers are swapped, header->prev points to next node technically.
            header= header->prev;
        }
        // swapping head pointer to tail and tail pointer to head as DLL has been reversed.
        head= tail;
        tail= anotherTemp;
    } // end of reverseList() function

};

int main()
{
    linkedList obj;
    int valueToBeInserted= 0;

    // creating and displaying the DLL

    cout<<"Enter the value that you want to insert in the DLL: (Zero to end)"<<endl;
    cin>>valueToBeInserted;
    while(valueToBeInserted != 0)
    {
        obj.createList(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"Doubly Linked List: ";
    obj.display();

    // reversing and printing the DLL

    cout<<"Doubly Linked List after reversing: ";
    obj.reverseList();
    obj.display();

    return 0;
}
