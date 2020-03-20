#include <iostream>
using namespace std;

// using template function
template <typename T>
T sumOfNumbers(T num1, T num2)
{
    T sum;
    sum= num1+num2;
    return sum;
}

int main()
{
    cout<<"Sum: "<<sumOfNumbers<int>(4,5)<<endl;
    cout<<"Sum: "<<sumOfNumbers<float>(4.7,5)<<endl;
    cout<<"Sum: "<<sumOfNumbers<char>('c','d')<<endl; // wrong answer but right bhawna.
    return 0;
}
