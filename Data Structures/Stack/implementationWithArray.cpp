#include <iostream>
using namespace std;


// structure of a stack

struct stackStructure
{
    // size of stack
    int size;
    // stores the index of last element
    int top;
    // pointer to the integer array
    int *array;
}stack;

// function to push element to stack

void push(int value)
{
    // checking if stack is full, then element can't be pushed
    if(stack.top == stack.size-1)
        cout<<"\nStack Overflow"<<endl;
    else
    {
        // increasing the top pointer of the array
        stack.top++;
        // inserting/pushing the value at the top of the stack
        stack.array[stack.top]= value;
    }
} // end of the push() value

// function to pop elements from stack

void pop()
{
    // value holds the data of popped element
    int value= 0;
    if(stack.top == -1)
        cout<<"\nUnderflow: Empty Stack !"<<endl;
    else
    {
        value= stack.array[stack.top];
        stack.top--;
        cout<<"\nValue popped: "<<value<<endl;
    }
} // end of pop() function

void peek()
{
    if(stack.top == -1)
        cout<<"\nUnderflow: Stack is empty!"<<endl;
    else
    {
        cout<<"\nPeeked Value at the top is: "<<stack.array[stack.top]<<endl;
    }
} // end of peek() function


int main()
{
    // initializing default value and size of stack ADT

    cout<<"Enter the size of the stack: ";
    cin>>stack.size;
    stack.array= new int[stack.size];
    stack.top= -1;

    // ****** stack Operations ******

    int option=0;
    int data= 0;
    cout<<"\nP.S. - Enter Zero to end the program!\n"<<endl;
    cout<<"\n1. Push Value to the Stack.\n2. Pop value from the stack.\n3. Peeked value from the stack.\n\nEnter the option: ";
    cin>>option;
    while(option != 0)
    {
        switch(option)
        {
            case 1:
                cout<<"\nEnter Data to push: ";
                cin>>data;
                push(data);
                cout<<"\nEnter the option again: ";
                cin>>option;
                break;
            case 2:
                pop();
                cout<<"\nEnter the option again: ";
                cin>>option;
                break;
            case 3:
                peek();
                cout<<"Enter the option again: ";
                cin>>option;
                break;
            default:
                cout<<"\nInvalid Choice. Try again!"<<endl;
                cout<<"\nEnter the option again: ";
                cin>>option;
        } // end of switch() statement

    } // end of while() loop

    return 0;
}
