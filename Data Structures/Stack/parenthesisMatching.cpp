#include <iostream>
#include <string.h>
using namespace std;

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

bool pop()
{
    if(stack.top == -1)
    {
        cout<<"Underflow of Stack"<<endl;
        return false;
    }
    else
    {
        // displaying the popped value and then decrementing the top pointer
        stack.top--;
    }
} // end of pop() function


int main()
{
    // boolean to keep track of the result of parenthesis matching
    bool match= false;

    // resetting the stack variables and attributes
    stack.top= -1;
    stack.array= new char[1000];

    // inserting parenthesis to stack to match for validity
    char expression[1000];
    cout<<"Enter the Expression to match the parenthesis: ";
    cin>>expression;
    int len= strlen(expression);

    // traversing through the character array and matching parenthesis
    for(int i=0; i<len-1; i++)
    {
        // if character is an opening bracket
        if(expression[i] == '(')
            push('(');
        // if character is a closing bracket
        else if(expression[i] == ')')
            match= pop();
        // if character is anything else we do nothing
        else
            continue;
    }

    if(stack.top == 0)
        cout<<"Parenthesis Matched"<<endl;
    else
        cout<<"Not matched"<<endl;
    return 0;
}
