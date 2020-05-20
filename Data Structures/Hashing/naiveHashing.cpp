#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the size of array: ";
    int size;
    cin>>size;
    int arr[size] = {0};

    // accepting size of the array where searching is required
    for(int i=0; i<size; i++)
        cin>>arr[i];

    long long hashTable[10000] = {0};
    int searchItem = 0;

    // mapping elements to the hash table (HASH FUNCTION is h(x)=x ) Hence, no collision but wastage of space!
    for(int i=0; i<size; i++)
        hashTable[arr[i]] = arr[i];

    cout<<"Enter the item to be searched: ";
    cin>>searchItem;

    // finding if key is present in hash table
    if(hashTable[searchItem] == searchItem)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}
