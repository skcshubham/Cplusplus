#include <iostream>
using namespace std;

#define size 10000

// structure of a queue

struct queueStructure
{
    int front;
    int rear;
    int *array;
}queue;

// function to push data to the queue ie, enqueue function

void enqueue(int data)
{
    // if there is no memory to be used to store more queue values
    if(queue.front == size-1)
        cout<<"Queue is Overflow. Memory FULL !!"<<endl;
    // the rear value is increased and data is added to the queue or array
    else
        queue.array[++queue.rear]= data;
} // end of enqueue()

// function to pop or delete data from the queue, ie, dequeue function

int dequeue()
{
    // if the queue is empty and front and rear both points to the same position or index
    if(queue.front == queue.rear)
    {
        cout<<"Queue is empty!!"<<endl;
        return '\0';
    }
    // if the queue has elements then the front position is increases, the value is sored and returned and then the index is nullified
    // because the front points to one place or index before the front of the queue
    else
    {
        int dequeuedItem= 0;
        dequeuedItem= queue.array[++queue.front];
        queue.array[queue.front]= '\0';
        return dequeuedItem;
    }
} //  end of dequeue() function

int main()
{
    // initializing the queue attributes to default
    queue.front= queue.rear= -1;
    queue.array= new int[size];

    int value, flag, option;
    cout<<"1. To add into the queue.\n2. To delete from the queue 0. To move out of the code or end code"<<endl;
    while(flag != 0)
    {
        cout<<"\nEnter option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter the value to be enqueued:"<<endl;
            cin>>value;
            while(value !=0)
            {
                enqueue(value);
                cin>>value;
            } // end of while
            break;
        case 2:
            cout<<"\nDeleted Key: "<<dequeue();
            break;
        case 0:
            flag= 0;
        default:
            cout<<"Invalid input. "<<endl;
        } // end of switch
    } // end of while()

    return 0;
}
