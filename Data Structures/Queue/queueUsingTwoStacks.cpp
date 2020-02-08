#include <iostream>
using namespace std;

// structure of stack

struct stackStructure
{
    // size of the stack
    int size;
    // points to top of the stack
    int top;
    // array to implement stack
    int *array;
}s1,s2;

/*
    Concept: To implement a Queue using two stacks we have to take care of few things:
    1. We only push in stack s1. Hence, enqueue function is simple, we simply push to stack s1.
    2. if we have to pop elements or dequeue it, it's done in stack s2 only but we have to take care of few things-
        a. If the s2 is empty, then we transfer all elements from s1 to s2 and then pop an element
        b. If both the stacks are empty, then the queue is empty.
        c. If s2 isn't empty, then we just dequeue the top of the stack s2.

    Hence, in simple words:
        Enqueue- s1
        Dequeue- s2
            but if both empty, then queue is empty

*/

// function to enqueue or insert in the queue(technically, a stack)

void push(stackStructure* s,int data)  // enqueue is done on stack s which is being passed
{

    /*
        (->) is used instead of (.) because dereferencing is done because structure is getting passed by function.
    */

    // to check if stack is full
    if(s->top == s->size-1)
        cout<<"Stack is full. Ain't No place left."<<endl;
    // if the stack isn't full
    else
    {
        // incrementing the top pointer and inserting
        ++s->top;
        s->array[s->top]= data;
    }
} // end of push()

// function to dequeue or delete from the queue(technically, a stack too)

int pop() // dequeue is done on stack s2
{
    // to check if stack s2 is empty
    if(s2.top == -1)
    {
        // if s1 is empty too, then both stacks are empty and hence Queue is empty
        if(s1.top == -1)
        {
            cout<<"Queue is empty. Both stacks are empty!!"<<endl;
            return -1;
        }
        // if s1 isn't empty, then we transfer elements from s1 to s2 and then pop
        else
        {
            // transferring s1 to s2
            while(s1.top != -1)
            {
                // pushing to s2, the popped element from s1
                push(&s2, s1.array[s1.top--]);
            }
            return s2.array[s2.top--];
        }
    }
    // if stack s2 isn't empty, then we simply pop the first element from s2
    else
    {
        return s2.array[s2.top--];
    }
} // end of pop()


int main()
{
    // initializing the stackStructure

    s1.top= s2.top= -1;
    cout<<"Enter the size of the stack: ";
    cin>>s1.size;
    // making the size of both stacks as same
    s2.size= s1.size;
    s1.array= new int[s1.size];
    s2.array= new int[s1.size];

    // writing the menu driven code

    int option, value;
    cout<<"\n1. To queue into the queue.\n2. To dequeue in the queue.\n3. To end the code."<<endl;

    while(option != 3)
    {
        cout<<"Enter the option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter the elements that you want to push: "<<endl;
            cin>>value;
            while(value != 0)
            {
                push(&s1, value);
                cin>>value;
            }
            break;
        case 2:
            cout<<"\nDequeued Element: "<<pop()<<endl;
            break;
        case 3:
            option= 3;
            break;
        default:
            cout<<"Wrong option. Please choose again."<<endl;
        }
    } // end of switch()

    return 0;
}
