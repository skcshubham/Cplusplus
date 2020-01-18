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
    linkedList()
    {
        head= tail= NULL;
    }

    // function to find the length of the doubly linked list

    int length()
    {
        int counter= 0;
        Node *temp= head;
        while(temp != NULL)
        {
            counter++;
            temp= temp->next;
        }
        return counter;
    } // end of length() function


    // function to create a doubly linked list

    Node* createList(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->prev= NULL;
        temp->next= NULL;
        // if linked list was empty
        if(head == NULL)
        {
            head= tail= temp;
            head->prev= head->next= NULL;
            temp= NULL;
            return head;
        }
        // if linked list contains more than one node
        else
        {
            tail->next= temp;
            temp->prev= tail;
            tail= temp;
            tail->next= NULL;
            temp= NULL;
            return head;
        }
    } // end of createList() function


    // function to display the doubly linked list

    void display(Node *header)
    {
        Node *temp= header;
        while(temp != NULL)
        {
            cout<<temp->data<<" <=> ";
            temp= temp->next;
        }
        cout<<endl;
    } // end of display() function


    // function to insert a node before the head of the doubly linked list

    Node* insertAtTheBeginning(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->prev= temp->next= NULL;
        // if linked list contains no node
        if(head == NULL)
        {
            head= tail= temp;
            head->prev= head->next= NULL;
            temp= NULL;
            return head;
        }
        // if linked list has nodes
        else
        {
            temp->next= head;
            head->prev= temp;
            head= temp;
            return head;
        }
    } // end of insertAtTheBeginning() function


    // function to insert a node at the end of the linked list

    Node* insertAtTheEnd(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->prev= temp->next= NULL;
        // if linked list was empty, inserting at the end would be similar to inserting at the beginning
        if(head == NULL)
        {
            // ************ calling insert at the beginning function *************
            Node *header= new Node;
            header= insertAtTheBeginning(value);
            return header;
        }
        // if linked list wasn't empty
        else
        {
            tail->next=temp;
            temp->prev= tail;
            temp->next= NULL;
            tail= temp;
            return head;
        }
    } // end of insertAtTheEnd() function

    // function to insert at any specific point

    Node* insertAtSpecificPosition(int value, int position)
    {
        // checking that length of DLL is more than position entered to stop pointer from moving out of scope & throw a segmentation error!
        if(length() < position)
        {
            cout<<"The position you entered is larger than length of linked list !!"<<endl;
            return head;
        }
        Node *temp= new Node;
        temp->data= value;
        temp->prev= temp->next= NULL;
        int pos=1;
        Node *ptr= head;
        // traveling to the position where node has to be inserted
        while(pos != position)
        {
            ptr= ptr->next;
            pos++;
        }

        // if the linked list was empty, then we call insert at the beginning function
        if(head == NULL || position == 0)
        {
            // ************ calling insert at the beginning function *************
            Node *header= new Node;
            header= insertAtTheBeginning(value);
            return header;
        }
        // if ptr reaches  the end, then we call insert at the end function
        else if(ptr == tail)
        {
            Node *header= new Node;
            header= insertAtTheEnd(value);
            return header;
        }
        // ******** if insertion has to be done at any other position *********
        else
        {
            // inserting node at the specified position
            temp->next= ptr->next;
            ptr->next->prev= temp;
            temp->prev= ptr;
            ptr->next= temp;
            return head;
        }
    } // end of insertAtSpecifiedPosition() function

};

int main()
{
    linkedList obj;
    int valueToBeInserted=0;

    // creating Doubly Linked List

    cout<<"Enter Elements that you want to insert in the doubly linked list: (Zero to end)"<<endl;
    cin>>valueToBeInserted;
    Node *header= NULL;
    while(valueToBeInserted != 0)
    {
        header= obj.createList(valueToBeInserted);
        cin>>valueToBeInserted;
    }

    // displaying doubly linked list

    cout<<"Doubly Linked list: ";
    obj.display(header);

    // inserting at the beginning of the linked list

    cout<<"Enter the value that you want to insert at the beginning of the doubly linked list: ";
    cin>>valueToBeInserted;
    header= obj.insertAtTheBeginning(valueToBeInserted);
    cout<<"Doubly Linked List: ";
    obj.display(header);

    // inserting at the end of the linked list

    cout<<"Enter the value that you want to insert at the end of the doubly linked list: ";
    cin>>valueToBeInserted;
    header= obj.insertAtTheEnd(valueToBeInserted);
    cout<<"Doubly Linked List: ";
    obj.display(header);

    // inserting at the specified position in the linked list

    cout<<"Enter the value that you want to insert: ";
    cin>>valueToBeInserted;
    cout<<"Enter the position where you want to insert: ";
    int pos=0;
    cin>>pos;
    header= obj.insertAtSpecificPosition(valueToBeInserted, pos);
    cout<<"Doubly Linked List: ";
    obj.display(header);

    return 0;
}
