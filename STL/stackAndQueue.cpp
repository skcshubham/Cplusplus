#include <iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    int size, num;
    cout<<"Enter the size of stack and queue: ";
    cin>>size;

    // declaring stack and queue
    stack <int> s;
    queue <int> q;

    // initializing values to stack and queue

    cout<<"Enter the elements in stack and queue: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>num;
        s.push(num);
        q.push(num);
    }

    // popping and displaying the stack

    cout<<"\nElements popped from stack: ";
    while ( !s.empty() )
    {
        cout<<s.top()<<" "; // returning the top element
        s.pop(); // removing the top element not returning it. Using else loop will never be false. Infy loop
    }


     // popping and displaying the queue

     cout<<"\nElements popped from queue: ";
     while( !q.empty() )
     {
         cout<<q.front()<<" "; // returning the front element as it's queue
         q.pop(); // popping out element to prevent infy loop
     }

    return 0;
}
