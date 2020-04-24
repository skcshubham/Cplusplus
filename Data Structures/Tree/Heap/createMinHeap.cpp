#include <iostream>
using namespace std;

// function to shuffle the array into a max heap

void minHeapify(int arr[], int boundary)
{
    int temp=arr[boundary], i= boundary;
    while(i > 1 && arr[i] > arr[i/2])
    {
        arr[i]= arr[i/2];
        i= i/2;
    }
    arr[i]= temp;
}


int main()
{
    int size;
    cout<<"Enter the size of the heap because I've used an array here: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the heap"<<endl;

    for(int i=0; i<size; i++)
        cin>>arr[i];


    // Heapifying


    for(int i=2; i<size; i++)
        minHeapify(arr, i);


    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    return 0;
}
