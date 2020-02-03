#include <iostream>
#include<cmath>
using namespace std;

#define size 1000

// structure of a stack

struct stackStructure
{
    int top;
    int* array;
}stack;

// function to check if the character is operand(a and b)

int isOperand(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 0;
    else
        return 1;
} // end of isOperand()

// function to push into the stack

void push(int data)
{
    if(stack.top == size-1)
        cout<<"Stack Overflow"<<endl;
    else
        stack.array[++stack.top]= data;
} // end of push()

// function to pop elements from the stack

int pop()
{
    if(stack.top == -1)
    {
         cout<<"Stack is empty!"<<endl;
         return 0;
    }
    else
        return stack.array[stack.top--];
} // end of pop()



/*
    This was one of the most challenging code I've written till date. The concept is that we accept the postfix expression in string format from the user
    and we traverse through each element one by one. We have implemented a integer stack here because only integers gets pushed to the stack until any
    operator is encountered and in that case two consecutive elements are popped from the stack and the operation is performed. First popped element
    is the second operand and second popped element is the first operand, then the answer is again pushed and this continues till the value exhausts from
    the string of expressions and then the last element in the integer stack will be the final answer of the expression.

    Time and Space Complexity= O(n)  ** efficient af!! **
*/



int main()
{
    // initializing the stack structure variables

    stack.top= -1;
    stack.array= new int[size];

    // to accept the postfix expression from the user
    char expression[size];
    cout<<"Enter postfix expression: ";
    cin>>expression;

    int firstOperand= 0, secondOperand= 0, answer= 0;

    for(int i=0; expression[i] != '\0'; i++)
    {
        // if the operand is a number, it gets pushed into the stack until a operator is encountered
        if(isOperand(expression[i]) == 1)
        {
            int integerExpression= (int)expression[i] -48;
            push(integerExpression);
        }
        // if operator is encountered
        else
        {
            // character value is popped and stored in the form of integer in variables to be computed
            secondOperand= pop();
            firstOperand= pop();

            // checking the operator and performing the calculations
            if(expression[i] == '+')
            {
                answer= firstOperand + secondOperand;
                push(answer);
            }
            else if(expression[i] == '-')
            {
                answer= firstOperand - secondOperand;
                push(answer);
            }
            else if(expression[i] == '*')
            {
                answer= firstOperand * secondOperand;
                push(answer);
            }
            else if(expression[i] == '/')
            {
                answer= firstOperand / secondOperand;
                push(answer);
            }
            else if(expression[i] == '^')
            {
                // power of the number is found out and pushed
                answer= pow(firstOperand, secondOperand);
                push(answer);
            }
            else
                cout<<"Weird Character in the expression."<<endl;
        }
    }

    // final answer is popped from the stack
    cout<<"Final Answer= "<<pop()<<endl;
    return 0;
}
