#include <iostream>
using namespace std;

#define datatype long long int

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        datatype num=0;
        cin>>num;
        datatype numberOfZero=0;
        while(num > 4)
        {
            numberOfZero+= num/5;
            num= num/5;
        }
        cout<<numberOfZero<<endl;
        // finds the number of trailing zero in the factorial of a number
    }
    return 0;
}
