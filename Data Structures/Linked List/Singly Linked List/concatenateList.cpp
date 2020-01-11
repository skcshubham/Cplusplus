#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class linkedList
{
public:
    Node *head1, *head2, *tail1, *tail2;
public:
    linkedList()
    {
        head1= head2= tail1= tail2= NULL;
    }

    // function to display the linked list

    void display(Node *head)
    {
        Node *temp= head;
        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp= temp->link;
        }
        cout<<endl;
    }

    // function to create 1st linked list

    void createList1(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        // if linked list is empty
        if(head1 == NULL)
        {
            head1= tail1= temp;
            temp= NULL;
        }
        // if linked list has one or more nodes
        else
        {
            tail1->link= temp;
            tail1= temp;
            temp= NULL;
        }
    }

    // function to create 2nd linked list

    void createList2(int value)
    {
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        // if linked list is empty
        if(head2 == NULL)
        {
            head2= tail2= temp;
            temp= NULL;
        }
        // if linked list has one or more nodes
        else
        {
            tail2->link= temp;
            tail2= temp;
            temp= NULL;
        }
    }

    // function to concatenate two linked list and returns head to the concatenated list

    Node* concatenate(Node *head1, Node *head2)
    {
        // if first list is empty, then head to second list is returned as concatenated
        if(head1 == NULL)
            return head2;
        // if second list is empty, then head to first list is returned as concatenated
        else if(head2 == NULL)
            return head1;
        // if both list is empty, then NULL is returned
        else if(head1 == NULL && head2 == NULL)
            return NULL;
        // if both list have nodes, then normal concatenation is performed
        else
        {
            Node *temp= new Node;
            temp= head1;
            while(temp->link != NULL)
            {
                temp= temp->link;
            }
            // links the end of the first list to the head of the second one
            temp->link= head2;
            // resets the head of the second list to NULL
            head2= NULL;
            // returns the head to the concatenated linked list
            return head1;
        }
    }

    // function to merge two sorted linked list without using any extra space

    Node* mergeList()
    {

    }
};

int main()
{
    linkedList obj;
    int valueToBeInserted;

    // creating first linked list

    cout<<"Enter the value of 1st Linked List (Zero to end) :\n";
    cin>>valueToBeInserted;
    while(valueToBeInserted != 0)
    {
        obj.createList1(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"First Linked List is: ";
    obj.display(obj.head1);

    // creating second linked list

    cout<<"Enter the value of 2nd Linked List (Zero to end) :\n";
    cin>>valueToBeInserted;
    while(valueToBeInserted != 0)
    {
        obj.createList2(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"Second Linked List is: ";
    obj.display(obj.head2);

    // concatenating the two linked list

    Node *concatenated= new Node;
    concatenated= obj.concatenate(obj.head1, obj.head2);
    cout<<"Concatenated Linked list is: ";
    obj.display(concatenated);

    return 0;
}
