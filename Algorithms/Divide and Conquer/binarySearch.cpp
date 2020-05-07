#include <iostream>
using namespace std;

// iterative binary search function
void binarySearch(int arr[], int key, int low, int high)
{
    while(low <= high)
    {
        int mid= (low+high)+1/2;
        if(arr[mid] == key)
        {
            cout<<"Element found at index "<<mid;
            return;
        }
        if(arr[mid] > key)
            high= mid-1;
        else
            low= mid+1;
    }
    cout<<"Element not found";
}

// recursive binary search function
int recursiveBinarySearch(int arr[], int key, int low, int high)
{
    int mid= (low+high+1)/2;

    // null condition/ breaking condition
    if(low > high)
        return 0;
    if(arr[mid] > key)
        recursiveBinarySearch(arr, key, low, mid-1);
    else if(arr[mid] < key)
        recursiveBinarySearch(arr, key, mid+1, high);
    else
        return mid;
}


int main()
{
    int size;
    cout<<"Enter the size of array = ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array:"<<endl;
    // accepting array
    for(int i=0; i<size; i++)
        cin>>arr[i];

    int num;
    cout<<"Enter the number to be searched: ";
    cin>>num;


    // calling binary search
    binarySearch(arr, num, 0, size);

    cout<<"Enter the number to be searched: ";
    cin>>num;

    // calling recursive binary search
    int flag=0;
    flag= recursiveBinarySearch(arr, num, 0, size);
    if(flag == 0)
        cout<<"Element not found";
    else
        cout<<"Element found at index "<<flag;

    return 0;
}
