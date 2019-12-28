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

        // pointer to the structure

        Node *head, *tail;

    public:

        // constructor to initialise the pointer to NULL value

        linkedList()
        {
            head= NULL;
            tail= NULL;
        }

        // implementing a linked list

        void createList(int value)
        {
            // temporary structure to hold the value temporarily
            Node *temp= new Node;
            temp->data= value;
            temp->link= NULL;
            // if the linked list is empty
            if(head== NULL)
            {
                head= temp;
                tail= temp;
                temp= NULL;
            }
            // if the linked list has other nodes
            else
            {
                tail->link= temp;
                tail= temp;
                temp= NULL;
            }

        } // end of createList()

        // function to traverse and display the linked list

        void display()
        {
            Node *temp= head;
            // the if block executes if the linked list isn't empty i.e, the temp doesn't point to NULL
            if(temp!= NULL)
            {
                // traversing till the temp node points to NULL
                while(temp)
                {
                    cout<<temp->data<<" -> ";
                    temp= temp->link;
                }
                cout<<endl;
            }
            else
            {
                cout<<"Linked List is empty!!"<<endl;
            }

        } // end of display()

        // function to insert in a sorted linked list

        void insertInSortedList(int valueToBeInserted)
        {
            // tempStruct is the temporary pointer to structure that has to be linked to the linked list
            Node *tempStruct= new Node;
            tempStruct->data= valueToBeInserted;
            tempStruct->link= NULL;
            // tempPointer is the the temporary pointer that is used to traverse the linked list
            Node *tempPointer= head;
            // if the linked list is empty
            if(tempPointer== NULL)
            {
                head= tempStruct;
                tail= tempStruct;
                tempStruct= NULL;
            }
            // if the linked list isn't empty
            else
            {
                // if the valueToBeInserted is the largest then there is no need to traverse. We attach it to the tail
                if(valueToBeInserted > tail->data)
                {
                    tail->link= tempStruct;
                    tail= tempStruct;
                    tempStruct= NULL;
                }
                // if the valueToBeInserted is the smallest then too we need not traverse. In this case, we attach it to the head
                else if(valueToBeInserted < head->data)
                {
                    Node *temp= head;
                    head= tempStruct;
                    tempStruct->link= temp;
                    tempStruct= NULL;
                }
                // if the valueToBeInserted isn't the largest or smallest
                else
                {
                    while(tempPointer->link->data <= valueToBeInserted)
                    {
                        tempPointer= tempPointer->link;
                    }
                    Node *holder= tempPointer->link;
                    tempPointer->link= tempStruct;
                    tempStruct->link= holder;
                }
            }

        } // end of insertInSortedList()

};

int main()
{
    linkedList obj;
    int data= 0;
    cout<<"Press Zero(0) to end the Linked List "<<endl;
    cin>>data;
    // loop to check if data isn't zero
    while(data)
    {
        obj.createList(data);
        cin>>data;
    }

    obj.display();

    cout<<"Enter the value that you want to be inserted in the sorted linked list: ";
    int insertedData= 0;
    cin>>insertedData;
    obj.insertInSortedList(insertedData);
    obj.display();
    return 0;
}
