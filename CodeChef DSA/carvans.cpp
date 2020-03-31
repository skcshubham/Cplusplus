#include <iostream>

// consider testcase: 4 8 5 3

using namespace std;

int main()
{
    long long int testcases;
    cin>>testcases;
    while(testcases--)
    {
        long long int numberOfCars;
        cin>>numberOfCars;
        long long int arr[numberOfCars];
        for(long long int i=0; i<numberOfCars; i++)
            cin>>arr[i];
        long long int maxSpeedCars= 1; // first one is always moving at max speed
        for(long long int i=0; i<numberOfCars-1; i++)
        {
            if(arr[i] > arr[i+1])
                maxSpeedCars++;
            else
                arr[i+1]=arr[i];

        }
        cout<<maxSpeedCars<<endl;
    }
    return 0;
}
