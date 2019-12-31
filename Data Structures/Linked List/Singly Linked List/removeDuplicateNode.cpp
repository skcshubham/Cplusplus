#include <bits/stdc++.h>
using namespace std;

//creating structure of a node
struct Node
{
    int data;
    Node *link;
};

class linkedList
{
private:
    Node *head, *tail;
public:
    linkedList()
    {
        head= NULL;
        tail= NULL;
    }

    // function to display linked list

    void display()
    {
        Node *temp= head;
        while(temp)
        {
            cout<<temp->data<<" -> ";
            temp= temp->link;
        }
    } // end of display()

    // function to create linked list

    void createList(int insertingData)
    {
        Node *temp= new Node;
        temp->data= insertingData;
        temp->link= NULL;
        // checking if list is empty
        if(head == NULL)
        {
            head= tail= temp;
            temp= NULL;
        }
        // if list has nodes initially
        else
        {
            tail->link= temp;
            tail= temp;
            temp= NULL;
        }
    } // end of createList()

    // function to remove duplicate nodes

    void removeDuplicate()
    {
        Node *ptr= head;
        Node *postptr= head->link;
        while(postptr!= NULL)
        {
            if(ptr->data != postptr->data)
            {
                ptr= postptr;
                postptr= postptr->link;
            }
            else
            {
                ptr->link= postptr->link;
                free(postptr);
                postptr= postptr->link;
            }

        }
    } // end of removeDuplicate()
};


int main()
{
    linkedList obj;
    int flag=0;
    cout<<"===== Press Zero (0) to end the linked list ====="<<endl;
    cin>>flag;
    while(flag != 0)
    {
        obj.createList(flag);
        cin>>flag;
    }
    cout<<"Before removing duplicates: ";
    obj.display();
    obj.removeDuplicate();
    cout<<"\nAfter removing duplicates: ";
    obj.display();
    return 0;
}
