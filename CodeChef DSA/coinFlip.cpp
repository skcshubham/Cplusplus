#include <iostream>
using namespace std;

#define datatype long long int

int main()
{
    datatype testcases;
    cin>>testcases;
    while(testcases--)
    {
        datatype games;
        cin>>games;
        while(games--)
        {
            datatype initialState, numberOfRounds, prediction;
            cin>>initialState>>numberOfRounds>>prediction;
            datatype arr[numberOfRounds];

            if(initialState == 1) // head
                for(datatype i=0; i<numberOfRounds; i++)
                    arr[i]=1;
            else // tail
                for(datatype i=0; i<numberOfRounds; i++)
                    arr[i]=-1;

            for(datatype i=0; i<numberOfRounds; i++)
            {
                for(datatype j=0; j<i; j++)
                    arr[j]= -arr[j];
            }


            datatype count=0;

            for(datatype i=0; i<numberOfRounds; i++)
            {
                if(prediction == 1)
                {
                    if(arr[i] == -1)
                        count++;
                }
                else
                {
                    if(arr[i] == 1)
                        count++;
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}




// ************ O(1) solution ************




#include <iostream>
#include <cmath>
using namespace std;

#define datatype long long int

int main()
{
    datatype testcases;
    cin>>testcases;
    while(testcases--)
    {
        datatype games;
        cin>>games;
        while(games--)
        {
            datatype initialState, numberOfRounds, prediction;
            cin>>initialState>>numberOfRounds>>prediction;

            int count= 0;

            if(initialState == 1)
            {
                if(prediction == 1 || numberOfRounds % 2 == 0)
                    count= numberOfRounds/2;
                else
                    count= numberOfRounds/2+1;
            }
            else
            {
                if(prediction == 1 && numberOfRounds % 2 != 0)
                    count= numberOfRounds/2+1;
                else
                    count= numberOfRounds/2;
            }



            cout<<count<<endl;
        }
    }
    return 0;
}
