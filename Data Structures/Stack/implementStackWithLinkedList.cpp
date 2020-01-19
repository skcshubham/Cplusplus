#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class linkedList
{
private:
    Node *top;
public:
    // constructor function
    linkedList()
    {
        top= NULL;
    }

    /* Quick Concept: If we have to implement stack then we must know its a LIFO type of ADT structure and hence, to implement
       it using a linked list we must implement a singly linked list where push and pop functionality both are done at the head
       of the linked list so that it gets popped and pushed in O(1) time and O(1) space.
    */

    // function to enable push functionality (Insertion at the head of list)

    void push(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        // if the stack/list is empty
        if(top == NULL)
        {
            top= temp;
            temp= NULL;
        }
        // if stack/list has elements/nodes
        else
        {
            temp->link= top;
            top= temp;
            temp= NULL;
        }
    } // end of push() function

    // function to enable pop functionality (deletion from the head)

    void pop()
    {
        Node *temp= top;
        // if stack/list is empty
        if(top == NULL)
            cout<<"Stack is empty!"<<endl;
        // if stack/list has nodes
        else
        {
            top= top->link;
            cout<<"Popped Value: "<<temp->data<<endl;
            free(temp);
        }
    } // end of pop() function

    // function to enable peek functionality (printing top/head element)

    void peek()
    {
        // if stack/list is empty
        if(top == NULL)
            cout<<"Stack is empty!"<<endl;
        else
            cout<<"Peeked Element: "<<top->data<<endl;
    } // end of peek() functionality

};

int main()
{
    linkedList stack;

    // *********** Stack Operations ***********

    int option= 0;
    int value= 0;
    cout<<"\nP.S. - Enter Zero to end the program!\n"<<endl;
    cout<<"\n1. Push Value to the Stack.\n2. Pop value from the stack.\n3. Peeked value from the stack.\n\nEnter the option: ";
    cin>>option;
    while(option != 0)
    {
        switch(option)
        {
        case 1:
            cout<<"Enter value to be pushed: ";
            cin>>value;
            stack.push(value);
            cout<<"Enter option again: ";
            cin>>option;
            break;
        case 2:
            stack.pop();
            cout<<"Enter option again: ";
            cin>>option;
            break;
        case 3:
            stack.peek();
            cout<<"Enter option again: ";
            cin>>option;
            break;
        default:
            cout<<"Invalid Option. Try again!"<<endl;
            cout<<"Enter option again: ";
            cin>>option;
        }
    }
    return 0;
}
