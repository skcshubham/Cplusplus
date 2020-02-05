#include <iostream>
using namespace std;

// structure of a node of linked list implementation of QUEUE

struct Node
{
    // integer data and self-referential structure
    int data;
    Node *link;
};

class Queue
{
private:
    Node *front, *rear;
public:
    // constructor
    Queue()
    {
        front= rear= NULL;
    }

    // function to insert in a queue

    void enqueue(int value)
    {
        Node *temp= new Node;
        temp->link= NULL;
        temp->data= value;
        // to check if the heap has exhausted
        if(temp == NULL)
        {
            cout<<"Queue is full !! Heap has exhausted!!"<<endl;
            return;
        }
        // if queue/list is empty
        if(front == NULL)
        {
            front= rear= temp;
        }
        // if list has nodes then we insert at tail as it's the implementation of a queue
        else
        {
            // attaching node to the tail or rear
            rear->link= temp;
            rear= temp;
        }
    } // end of enqueue

    // function to dequeue or delete value from a queue

    int dequeue()
    {
        // to check if the queue/list is empty
        if(front == NULL)
        {
            cout<<"Queue Is Empty!"<<endl;
            return -1;
        }
        // if the queue isn't empty and has nodes (follow FIFO)
        else
        {
            // incrementing the head and returning the data inside head
            Node *temp= front;
            front= front->link;
            return temp->data;
        }
    } // end of dequeue()
};

int main()
{
    // creating object of queue
    Queue Q;
    int value= 0, flag= 0, option= 0;

    // creating a menu driven code

    cout<<"1. To insert to the queue\n2. To Delete from the queue\n3. To exit from the code"<<endl;
    while(flag !=3)
    {
        cout<<"\nEnter your option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter data to be inserted to queue: (Zero to end)"<<endl;
            cin>>value;
            while(value != 0)
            {
                Q.enqueue(value);
                cin>>value;
            } // end of while()
            break;
        case 2:
            cout<<"Deleted item: "<<Q.dequeue();
            break;
        case 3:
            flag= 3;
            break;
        default:
            cout<<"Wrong option. Try again!"<<endl;
        } // end of switch
    } //  end of while

    return 0;
}
