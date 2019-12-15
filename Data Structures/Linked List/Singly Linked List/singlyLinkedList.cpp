#include <bits/stdc++.h>
using namespace std;

// creating structure of a node
struct node
{
    int data;
    node *link;
};

class linkedList
{
    private:

        // node to access linked list
        node *head, *tail;

    public:

        // constructor to assign value to the private variable
        linkedList()
        {
            // assigning null to newly created pointer
            head= NULL;
            tail= NULL;
        }


        // function to find the length of the array

        int length()
        {
            node *p= new node;
            int len=0;
            p= head;

            // traversing the linked list and using len variable as counter
            while(p)
            {
                ++len;
                p= p->link;
            }
            return len;
        } // end of length()

        // function to create linked list
        void create(int value)
        {
            // creating new structure to hold data
            node *temp= new node;
            temp->data= value;
            temp->link= NULL;

            // if the linked list is empty
            if(head== NULL)
            {
                // setting head and tail node to temp node and setting temp node to NULL
                head= temp;
                tail= temp;
                temp= NULL;
            }
            else
            {
                // setting pointer of tail node to the temp node and mapping the temp node to the tail structure
                tail->link= temp;
                tail= temp;
            }
        } // end of create()

        void display()
        {
            // temporary node to traverse the linked list
            node *temp= new node;
            temp= head;

            // traversing through the liked list and printing the data
            while(temp)
            {
                cout<<temp->data<<" -> ";
                temp= temp->link;
            }

            // changing the line or new line command
            cout<<endl;
        } // end of display()



        void insertAtBeginning(int value)
        {

            // temp stucture to hold the value temporarily
            node *temp= new node;
            temp->data= value;
            temp->link= NULL;

            // if the linked list is empty the head and tail are same
            if(head== NULL)
            {
                head= temp;
                tail= temp;
                temp= NULL;
            }

            // if the linked list isn't empty then the temp structure is inserted at the last
            else
            {
                temp->link= head;
                head= temp;
                temp= NULL;
            }
        } // end of insertAtBeginning()

        void insertAtSpecificPosition(int value, int position)
        {
            node *temp= new node;
            temp->data= value;
            temp->link= NULL;

            // p structure to point to the node where the new temp node is to be inserted
            node *p= new node;
            p= head;

            // if the linked list is empty, we're inserting at the start as there is no node to traverse
            if(p== NULL)
            {
                head= temp;
                tail= temp;
                temp= NULL;
            }

            else
            {
                // if the linked list isn't empty and the position isn't empty
                if(position< length() && position!= 0)
                {
                    // traversing through the linked list
                    for(int i=1; i< position-1; i++)
                    {
                        p= p->link;
                    }
                    temp->link= p->link;
                    p->link= temp;
                }
                else
                {
                    cout<<"Position you've entered is larger than the length of the linked list!"<<endl;
                }
            }

        } // end of insertAtSpecificPosition()

        // function to insert a node at the end

        void insertAtEnd(int value)
        {
            node *temp= new node;
            temp->data= value;
            temp->link= NULL;

            // creating new node to traverse the linked list
            node *p= new node;
            p= head;
            while(p->link!= NULL)
            {
                // moving one node ahead at a time
                p=p->link;
            }

            // adding node to the end of the linked list
            p->link= temp;
            temp->link= NULL;
        } // end of insertAtEnd()

        // function to delete the first node

        void deleteFirstNode()
        {
            node *p= new node;
            p= head;
            if(p== NULL)
            {
                cout<<"Linked list is empty!"<<endl;
            }
            else
            {
                head= head->link;
                free(p);
            }
        } // end of deleteFirstNode()

        // function to delete the node at a given position

        void deleteSpecificPosition(int position)
        {
            // preptr pointer points to one node before the position where the new node has to be inserted
            node *preptr= new node;

            // postptr points to the position where the value is to be inserted
            node *postptr= new node;
            postptr= head;
            preptr= NULL;
            if(postptr== NULL)
            {
                cout<<"Linked list is empty!"<<endl;
            }
            else
            {
                if(position< length() && position!= 0)
                {
                    for(int i=1; i<position; i++)
                    {
                        // preptr always points to the one node before the postptr
                        preptr= postptr;
                        postptr= postptr->link;
                    }
                    preptr->link= postptr->link;
                    free(postptr);
                }
                else
                {
                    cout<<"Position you've entered is larger than the length of the linked list!"<<endl;
                }
            }

        } // end of deleteSpecificPosition()

        // function to delete the last node

        void deleteLastNode()
        {
            node *temp= new node;
            temp= head;
            if(temp== NULL)
            {
                cout<<"Linked list is empty!"<<endl;
            }
            else
            {
                // temp pointer points to second last node
                while(temp->link->link!= NULL)
                {
                    temp= temp->link;
                }
                // freeing the last node
                free(temp->link);
                temp->link= NULL;
            }
        }
};


int main()
{
    // creating object for the class linked list
    linkedList obj;

    int loopTime= 8;


    cout<<"1: Create a linked list.\n2: Display the linked list.\n3: Insert a node at the beginning of the linked list.";
    cout<<"\n4: Insert a node in the specific position of the linked list.\n5: Insert a node at the end of the linked list.";
    cout<<"\n6: Delete a node from the beginning of the linked list.\n7: Delete the node from the specified position int the linked list.";
    cout<<"\n8: Delete a node from the end of the linked list.\n";

    int option;
    while(loopTime)
    {
        cout<<"Enter your Choice: ";
        cin>>option;

        switch(option)
        {
            case 1:
                {
                    --loopTime;
                    int flag= 0;
                    cout<<"Type 0 to exit the linked list"<<endl;
                    cin>>flag;

                    // creating linked list

                    while(flag!=0)
                    {
                        obj.create(flag);
                        cin>>flag;
                    }

                    break;
                }

            case 2:
                {
                    --loopTime;
                    // displaying linked list

                    obj.display();

                    break;
                }

            case 3:
                {
                    --loopTime;
                    // inserting at the beginning

                    int value;
                    cout<<"\nEnter the value that you want to insert ";
                    cin>>value;
                    obj.insertAtBeginning(value);
                    obj.display();

                    break;
                }

            case 4:
                {
                    --loopTime;
                    // inserting at specific position

                    int value1, position1;
                    cout<<"Enter the value that you want to insert: ";
                    cin>>value1;
                    cout<<"\nEnter the position in which you want to insert: ";
                    cin>>position1;

                    obj.insertAtSpecificPosition(value1, position1);
                    obj.display();

                    break;
                }

            case 5:
                {
                    --loopTime;
                    // inserting at the end

                    int value2;
                    cout<<"\nEnter the value that you want to insert ";
                    cin>>value2;

                    obj.insertAtEnd(value2);
                    obj.display();

                    break;
                }

            case 6:
                {
                    --loopTime;
                    // deleting the first node

                    obj.deleteFirstNode();
                    obj.display();

                    break;
                }

            case 7:
                {
                    --loopTime;
                    // deleting the node at specified position

                    int position2;
                    cout<<"\nEnter the position where you want to delete ";
                    cin>>position2;

                    obj.deleteSpecificPosition(position2);
                    obj.display();

                    break;
                }

            case 8:
                {
                    --loopTime;
                    // deleting node from the end

                    obj.deleteLastNode();
                    obj.display();

                    break;
                }

            default:
                {
                    loopTime=0;
                    cout<<"Wrong Choice !!";
                }

        } // end of switch
    } // end of while loop


    return 0;
}
