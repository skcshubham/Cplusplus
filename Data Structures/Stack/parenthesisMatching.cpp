#include <iostream>
#include <string.h>
using namespace std;
bool isMatching= true;

// structure of a stack

struct stackStructure
{
    // top pointer of the stack
    int top;
    // pointer to the array/stack
    char *array;
}stack;

// function to push element to stack

void push(char data)
{
    if(stack.top == 999)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    else
    {
        // incrementing the top and then pushing data to the stack
        stack.top++;
        stack.array[stack.top]= data;
    }
} // end of push() function

// function to pop elements from the stack

char pop()
{
    if(stack.top == -1)
        isMatching= false;
    else
        // returning the popped value and then decrementing the top pointer
        return stack.array[stack.top--];

} // end of pop() function


int main()
{
    // match variable to keep track that closing bracket and opening brackets are in sequence
    char match= '\0';

    // resetting the stack variables and attributes
    stack.top= -1;
    stack.array= new char[1000];

    cout<<"Enter the Expression to match the parenthesis: ";
    cin>>stack.array;

    // traversing through the character array and matching parenthesis
    for(int i=0; stack.array[i] != NULL; i++)
    {
        // if character is an opening bracket
        if(stack.array[i] == '(' || stack.array[i] == '{' || stack.array[i] == '[')
            push(stack.array[i]);
        // if character is a closing bracket
        else if(stack.array[i] == ')' || stack.array[i] == '}' || stack.array[i] == ']')
        {
            match= pop();
            // if the element popped is ( but top of the stack is } or ]
            if(match == '(' && (stack.array[i] == '}' || stack.array[i] == ']'))
                isMatching= false;
            // if the element popped is { but top of the stack is ) or ]
            else if(match == '{' && (stack.array[i] == ')' || stack.array[i] == ']'))
                isMatching= false;
            // if the element popped is [ but top of the stack is } or )
            else if(match == '[' && (stack.array[i] == '}' || stack.array[i] == ')'))
                isMatching= false;
        }
        // if character is anything else we do nothing
        else
            continue;
    }

    if(isMatching == true && stack.top == -1)
        cout<<"Parenthesis Matched"<<endl;
    else
        cout<<"Not matched"<<endl;
    return 0;
}
