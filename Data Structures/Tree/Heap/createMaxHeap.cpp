#include <iostream>
using namespace std;

void maxHeapify(int arr[], int position)
{
    int temp = arr[position];
    int i = position;
    while( i > 1 && temp > arr[i/2] )
    {
        arr[i]= arr[i/2];
        i= i/2;
    }
    arr[i] = temp;
}

int main()
{
    int size;
    cout<<"Enter the size of the heap: ";
    cin>>size;
    size++;
    int arr[size];

    cout<<"Enter the elements in the heap: "<<endl;
    for(int i=1; i<size; i++)
        cin>>arr[i];

    // calling maxHeapify function

    for(int i=2; i<size; i++)
        maxHeapify(arr, i);

    // printing maxHeap

    cout<<"Elements in the heap are: ";
    for(int i=1; i<size; i++)
        cout<<arr[i]<<" ";

    return 0;
}
