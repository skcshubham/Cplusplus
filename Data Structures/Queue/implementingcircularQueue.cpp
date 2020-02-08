#include <iostream>
using namespace std;

// structure of a queue

struct queueStructure
{
    // size of the circular queue
    int size;
    // front pointer
    int front;
    // rear pointer
    int rear;
    // array to implement queue
    int *array;
}queue;

/*
    Concept: Initially, both front and rear starts from zero, so the condition for empty queue is when front == rear. We insert at rear end
    and delete at the front end. One location should be left empty and should not be used because it is used to check the condition for full queue.
    We increase the rear end and then insert until it reaches the end of the array. When the rear reaches end then it is again brought back to the
    first index if it's empty and insertion takes place again. This gives the illusion of circular queue. Array is not circular but we move our
    front and rear pointers circularly and hence the name, circular queue.
*/

// function to perform insertion/enqueue

void enqueue(int value)
{
    // if circular queue is full
    if((queue.rear+1)%queue.size == queue.front)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    // if the queue isn't full
    else
    {
        // increasing the value of the rear by one to insert in the queue
        queue.rear= ((queue.rear+1)%queue.size);
        // inserting in the queue
        queue.array[queue.rear]= value;
    }
} // end of enqueue()

// function to perform dequeue/deletion

int dequeue()
{
    // to check if the queue is empty
    if(queue.front == queue.rear)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    // if the queue isn't empty
    else
    {
        // incrementing the front pointer and then storing the current front value to temp integer variable
        int value;
        queue.front= ((queue.front+1)%queue.size);
        value= queue.array[queue.front];
        // setting the current front pointer to null
        queue.array[queue.front]= '\0';
        // returning the value
        return value;
    }
} // end of dequeue()


int main()
{
    // setting the default values of queueStructure

    queue.front= queue.rear= 0;
    cout<<"Enter the size of the queue: ";
    cin>>queue.size;
    // creating one size extra than user input because we have to keep one cell empty to check for full condition of the queue
    queue.array= new int[++queue.size];

    // menu driven code

    cout<<"\n1. To enqueue or insert in the queue.\n2. To dequeue or delete from the queue.\n3. To end the code."<<endl;
    int option= 0, data;
    while(option != 3)
    {
        cout<<"\nEnter the choice: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter value that you want to insert: "<<endl;
            cin>>data;
            while(data != 0)
            {
                enqueue(data);
                cin>>data;
            }
            break;
        case 2:
            cout<<"Deleted value: "<<dequeue()<<endl;;
            break;
        case 3:
            option= 3;
            break;
        default:
            cout<<"Invalid Choice!"<<endl;

        } // end of switch()
    } // end of while()

    return 0;
}
