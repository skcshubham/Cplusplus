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
    // constructor function to initialize pointers to NULL
    linkedList()
    {
        head= tail= NULL;
    }

    //function to count the length of the DLL

    int length()
    {
        int len= 0;
        Node *temp= head;
        while(temp != NULL)
        {
            len++;
            temp= temp->next;
        }
        return len;
    } // end of length() function

    // function to create a doubly linked list

    void createList(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->prev= temp->next= NULL;
        // if linked list was empty
        if(head == NULL)
        {
            head= tail= temp;
            temp= NULL;
        }
        // if linked list has nodes
        else
        {
            tail->next= temp;
            temp->prev= tail;
            tail= temp;
            tail->next= NULL;
        }
    } // end of createList() function

    // function to display the doubly linked list

    void display()
    {
        Node *temp= head;
        // if linked list was empty
        if(head == NULL)
        {
            cout<<"Empty !!"<<endl;
            return;
        }
        else
        {
            while(temp != NULL)
            {
                cout<<temp->data<<" <==> ";
                temp= temp->next;
            }
            cout<<endl;
        }
    } // end of display() function

    // function to delete the head node of the doubly linked list

    void deleteFromTheHead()
    {
        Node *temp= head;
        // if linked list was empty
        if(head == NULL)
        {
            cout<<"Empty !!"<<endl;
            return;
        }
        // if list had nodes
        else
        {
            // moving head one node ahead and freeing the OG head
            head= head->next;
            head->prev= NULL;
            free(temp);
        }
    } // end of deleteFromTheHead() function

    // function to delete the node from the end

    void deleteFromTheEnd()
    {
        Node *temp= tail;
        // condition for empty linked list
        if(tail == NULL || head == NULL)
        {
            cout<<"Empty !!"<<endl;
            return;
        }
        // if DLL has nodes
        else
        {
            // moving the tail one node behind and freeing the OG tail
            tail= tail->prev;
            tail->next= NULL;
            free(temp);
        }
    } // end of deleteFromTheEnd() function

    // function to delete the node from the specific position in the linked list

    void deleteFromTheSpecificPosition(int position)
    {
        int pos= 1;
        Node *temp= head;
        // if linked list was empty
        if(head == NULL)
        {
            cout<<"Empty !!"<<endl;
            return;
        }
        // if position given is larger than the length of the doubly linked list
        else if(position > length())
        {
            cout<<"The position is larger than the length of the list !"<<endl;
            return;
        }
        // if everything is okay
        else
        {
            // moving temp pointer to the deletion area
            while(pos != position)
            {
                temp= temp->next;
                pos++;
            }
            // making the changes in the link so that previous node points to the node next to the deleted node
            temp->prev->next= temp->next;
            temp->next->prev= temp->prev;
            // freeing up the node that has to the deleted
            free(temp);
        }
    } // end of deleteFromTheSpecificPosition() function

};

int main()
{
    linkedList obj;
    int valueToBeInserted= 0;

    // creating and displaying the doubly linked list

    cout<<"Enter the value that you want to insert in the DLL: (Zero to end)"<<endl;
    cin>>valueToBeInserted;
    while(valueToBeInserted != 0)
    {
        obj.createList(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"Doubly Linked List: ";
    obj.display();

    // deleting node from the head and displaying it

    obj.deleteFromTheHead();
    cout<<"DLL after deleting the head node: ";
    obj.display();

    // deleting node from the end or tail and displaying it

    obj.deleteFromTheEnd();
    cout<<"DLL after deleting the tail/end node: ";
    obj.display();

    // deleting node from the specified position from the DLL and displaying it

    int position= 0;
    cout<<"Enter the position of node that you want to delete: ";
    cin>>position;
    obj.deleteFromTheSpecificPosition(position);
    cout<<"DLL after deleting position "<<position<<" node: ";
    obj.display();

    return 0;
}
