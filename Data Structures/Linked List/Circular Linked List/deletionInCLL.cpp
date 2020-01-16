#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class linkedList
{
public:
    Node *head, *list1;
public:
    // constructor to initialize the pointer to NULL whenever object is created
    linkedList()
    {
        head= list1= NULL;
    }

    // function to display the circular linked list

    void display(Node *header)
    {
        // if the linked list isn't empty, then we traverse till the node is equal to head again
        if(header != NULL)
        {
            Node *temp= header;
            // using do while loop because if i would have used while then loop would've been false because eventually temp == header
            do
            {
                cout<<temp->data<<" -> ";
                temp= temp->link;
            }
            while(temp != header);
            cout<<endl;
        }
        // if linked list was empty
        else
        {
            cout<<"The Linked List is empty !!"<<endl;
        }

    } // end of display() function

    // function to create circular linked list

    Node* createList(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        // if linked list is empty and has no node
        if(head == NULL)
        {
            head= temp;
            temp->link= head;
        }
        else
        {
            Node *last=head;
            while(last->link != head)
                last= last->link;
            last->link= temp;
            temp->link= head;
            return head;
        }

    } // end of createList() function

    // function to delete node from the beginning circular linked list

    Node* deleteFromBeginningOfList()
    {
        Node *first= head;
        Node *last= head;
        // To check if list is empty to avoid segmentation fault
        if(head == NULL)
        {
            cout<<"Linked List is empty, Hence, nothing could be deleted !!"<<endl;
            return head;
        }
        else
        {
            // traversing to the end node to relink it to the new head of the CLL bc the old head was deleted
            while(last->link != head)
                last= last->link;
            // relinking last node to one node ahead of the head and freeing the initial head
            head= head->link;
            free(first);
            last->link= head;
            // returning the pointer to the head of the CLL
            return head;
        }
    } // end of the deleteFromTheList()


    // function to delete specific node from the CLL

    Node* deleteFromSpecificPosition(int position)
    {
        Node *pointer= head;
        Node *prePointer= NULL;
        // if the linked list was empty
        if(head == NULL)
        {
            cout<<"Linked List is empty, Hence nothing could be deleted !!"<<endl;
            return head;
        }
        // deleting from position zero hence invalid operation
        else if(position == 0)
        {
            cout<<"Deleting a node from position 0 is impossible, are you dumb?"<<endl;
            return head;
        }
        // deleting from position 1 calls deleteFromBeginningOfList() function
        else if(position == 1)
        {
            Node *Temp= new Node;
            Temp= deleteFromBeginningOfList();
            return Temp;
        }
        // if deletion has to be done from some other position, then we loop through the list and delete it and relink it.
        else
        {
            int pos=1;
            // moving pointer to the node which is to be deleted
            while(pos != position)
            {
                // prePointer holds one node before the node which is to be deleted
                prePointer= pointer;
                // pointer points to the node which is to be deleted and prePointer lags by one node
                pointer= pointer->link;
                // position is increased each time by one position/node
                pos++;
            }
            // relinking the node with new adjacent node and deleting the node at the given position
            prePointer->link= prePointer->link->link;
            free(pointer);
            prePointer= head;
            // returning the head pointer to the modified CLL
            return head;
        }
    } // end of deleteFromSpecificPosition()
};

int main()
{
    linkedList obj;

    // creating the circular linked list

    int insertInTheList=0;
    cout<<"Enter the element that you want to insert in linked list: (Zero to exit)"<<endl;
    cin>>insertInTheList;
    while(insertInTheList != 0)
    {
        obj.list1= obj.createList(insertInTheList);
        cin>>insertInTheList;
    }
    cout<<"Linked List: ";
    obj.display(obj.list1);

    //deleting the first node of the circular linked list

    Node *Temp= new Node;
    cout<<"Circular Linked List after deleting first node: ";
    Temp= obj.deleteFromBeginningOfList();
    obj.display(Temp);

    // deleting the node at a given position in the circular linked list

    int position=0;
    cout<<"Enter position of the node that you want to delete: ";
    cin>>position;
    Temp= obj.deleteFromSpecificPosition(position);
    cout<<"Linked List after deleting from "<<position<<" position: ";
    obj.display(Temp);
    return 0;
}
