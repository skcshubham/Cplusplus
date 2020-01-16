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
    Node *head;
public:
    linkedList()
    {
        head= NULL;
    }

    // function to display circular linked list

    void display(Node *head)
    {
        if(head != NULL)
        {
            // temp pointer is used to traverse the circular linked list
            Node *temp= head;
            do
            {
                cout<<temp->data<<" -> ";
                temp= temp->link;
            }
            while(temp != head);
            cout<<endl;
        }
        else
        {
           cout<<"Linked List is EMPTY !!"<<endl;
        }
    } // end of display() function

    // function to create a circular linked list

    Node* createList(int value)
    {
        // temp node is inserted to the circular linked list
        Node *temp= new Node;
        temp->data= value;
        temp->link= NULL;
        // if the CLL is empty, then node is inserted and made to point to itself
        if(head == NULL)
        {
            head= temp;
            temp->link= head;
            return head;
        }
        // if CLL isn't empty, then node is inserted at the end.
        else
        {
            // last pointer is used to point to the end of the inked list where curvature occurs so as to add a new node.
            Node *last= head;
            // traversing the CLL till the curve
            while(last->link != head)
                last= last->link;
            // last link is made to point to the new node
            last->link= temp;
            // new node is made to point to the head to maintain circularity. (is that even a word?)
            temp->link= head;
            // returning pointer to head of the CLL
            return head;
        }
    }

    // function to insert a node at the beginning of the circular linked list

    Node* insertAttheBeginning(int value)
    {
        /*  In these insertions, we have to reach to the end of the linked list where circularity occurs
            and then we insert a new node there.
        */
        if(head != NULL)
        {
            // creating a node to be inserted
            Node *temp= new Node;
            temp->data= value;
            temp->link= NULL;

            // node to reach the last node of CLL where circularity occurs
            Node *last= head;
            while(last->link != head)
                last= last->link;
            // making the last node point to new first node
            last->link= temp;
            // making the new first node point to the old head
            temp->link= head;
            // making temp the new head of our CLL
            head= temp;
            return temp;
        }
        else
        {
            cout<<"\nLinked List is empty!!"<<endl;
            return head;
        }
    } // end of insertAtTheBeginning() function

    // function to insert a node at the end of the circular linked list

    void insertAtTheEnd(int value)
    {
        if(head != NULL)
        {
            // node to reach the end of CLL (beginning of circularity)
            Node *last= head;
            while(last->link != head)
                last= last->link;
            // node which is to be inserted at the end
            Node *temp= new Node;
            temp->data= value;
            temp->link= NULL;
            // making the last node point to the new last node
            last->link= temp;
            // making the new last node point to the head to make the linked list circular
            temp->link= head;
        }
        else
        {
            cout<<"\nLinked List is empty!!"<<endl;
        }

    } // end of the insertAtTheEnd() function

    void insertAtSpecificPosition(int value, int position, Node *newHead)
    {
        if(newHead != NULL)
        {
            Node *temp= new Node;
            temp->data= value;
            temp->link= NULL;
            int pos= 1;
            Node *pointer= newHead;
            if(position == 0)
            {
                cout<<"Zero isn't a real position asshole! You trying to break my code?";
                return;
            }
            while(pos != position)
            {
                pointer= pointer->link;
                pos++;
            }
            temp->link= pointer->link;
            pointer->link= temp;
        }
        else
        {
            cout<<"\nLinked List is empty!!"<<endl;
        }

    } // end of insertAtSpecificPosition() function

};

int main()
{
    linkedList obj;
    cout<<"Enter elements of Linked List: (Zero to end the list)\n";
    int valueToBeInserted=0;
    cin>>valueToBeInserted;
    Node *list1= NULL;
    while(valueToBeInserted != 0)
    {
        list1= obj.createList(valueToBeInserted);
        cin>>valueToBeInserted;
    }
    cout<<"Linked list is: ";
    obj.display(list1);
    int value;
    cout<<"Value that you want to insert at the beginning: ";
    cin>>value;
    list1= obj.insertAttheBeginning(value);
    cout<<"Linked List after inserting at the beginning: ";
    obj.display(list1);
    cout<<"\nValue that you want to insert at the end: ";
    cin>>value;
    obj.insertAtTheEnd(value);
    cout<<"\nLinked list after inserting at the end: ";
    obj.display(list1);
    int position=0;
    value=0;
    cout<<"\nEnter the value and position where you want to insert:\n";
    cin>>value>>position;
    obj.insertAtSpecificPosition(value, position, list1);
    cout<<"\nLinked List after inserting at specific position: ";
    obj.display(list1);
    return 0;
}
