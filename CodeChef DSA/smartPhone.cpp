#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int customerNumber;
    cin>>customerNumber;
    unsigned long long int arr[customerNumber];

    for(unsigned long long int i=0; i<customerNumber; i++)
        cin>>arr[i];

    sort(arr, arr+customerNumber);

    unsigned long long int max= arr[0]*customerNumber;
    for(unsigned long long int i=1; i<customerNumber; i++)
    {
        unsigned long long int income= arr[i]*(customerNumber-i);
        if(max < income)
            max= income;
    }
    cout<<max;
    return 0;
}
