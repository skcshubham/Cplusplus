#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class linkedlist
{
private:
    Node *head, *tail;
public:
    linkedlist()
    {
        head= tail= NULL;
    }

    // function to display circular linked list

    void display(Node *head)
    {
        Node *temp= head;
        // increasing temp and printing until the temp header returns back to head because it's circular LL.
        do
        {
            cout<<temp->data<<" -> ";
            temp= temp->link;
        }
        while(temp != head);
    } // end of display()

    // function to create a circular linked list and returning pointer to the head of the list

    Node* createList(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        if(head == NULL)
        {
            // making temp node the head of LL
            head= temp;
            // relinking the pointer of head to itself to make it circular linked list
            temp->link= head;
        }
        else
        {
            Node *last= head;
            // moving the last pointer to the last node which points back to head itself
            while(last->link != head)
                last= last->link;
            // linking the last node to the newly inserted node and not to head
            last->link= temp;
            // pointing the newly inserted node to head to make the LL circular
            temp->link= head;
            return head; // ***************** o idea how this fucking works, but it does!!!! *******************
        } // end of createList()

    }
};

int main()
{
    linkedlist obj;
    int valueToBeInserted=0;
    cout<<"Enter the value that you want to insert in circular LL: (Zero to end)\n";
    cin>>valueToBeInserted;
    Node *listhead= new Node;
    while(valueToBeInserted != 0)
    {
        listhead= obj.createList(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"Circular Linked List: ";
    obj.display(listhead);

    return 0;
}
