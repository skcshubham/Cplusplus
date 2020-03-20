#include <iostream>
#include<list>
#include<iterator>

using namespace std;

int main()
{
    // ------ list is a doubly linked list --------

    int size, num;

    cout<<"Enter the size of the list: ";
    cin>>size;

    // declaring list
    list <int> l;

    cout<<"Enter the elements of the list: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>num;
        l.push_back(num);
    }

    // displaying using an iterator

    cout<<"\nElements in the list are: ";
    list <int> :: iterator it;
    for(it = l.begin(); it != l.end(); ++it)
        cout<<*it<<" ";


    l.reverse();
    cout<<"\nReversed Elements in the list are: ";
    for(it = l.begin(); it != l.end(); ++it)
        cout<<*it<<" ";


    l.sort();
    cout<<"\nSorted Elements in the list are: ";
    for(it = l.begin(); it != l.end(); ++it)
        cout<<*it<<" ";

    return 0;
}
