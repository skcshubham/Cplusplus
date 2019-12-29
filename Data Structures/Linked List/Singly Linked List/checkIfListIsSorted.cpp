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
        Node *head, *tail;
    public:
        // constructor to initialise the initial value
        linkedList()
        {
            head= tail= NULL;
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
            if(!head)
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

        // function to check if list is sorted

        int isSorted()
        {
            Node *temp= head;
            while(temp->link != NULL)
            {
                // if the value in the current node is larger than the value in next node
                if(temp->data > temp->link->data)
                {
                    // than the list isn't sorted and we return negative -1 that signifies false value
                    return -1;
                }
                temp= temp->link;
            }
            // else 1 gets returned which shows that the list is sorted
            return 1;
        } // end of isSorted()

};

int main()
{
    linkedList obj;
    int flag= 0,insertData= 0;
    cout<<"Type Zero (0) to end the list! "<<endl;
    cin>>insertData;
    while(insertData)
    {
        obj.createList(insertData);
        cin>>insertData;
    }
    cout<<"Linked List is: ";
    obj.display();
    flag= obj.isSorted();
    if(flag == 1)
        cout<<"\nThe linked list is sorted!"<<endl;
    else
        cout<<"\nThe linked list is unsorted!"<<endl;
    return 0;
}
