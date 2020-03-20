#include <iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v;
    int limit, num= 0;
    cout<<"Enter size ";
    cin>>limit;
    cout<<"Enter elements: "<<endl;

    // inserting

    for(int i=0; i<limit; i++)
    {
        cin>>num;
        v.push_back(num);
    }

    // displaying normally using index

    cout<<"\nVector elements: ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";

    // using iterators

    vector <int> :: iterator i;
    cout<<"\nVector elements: ";
    for(i= v.begin(); i != v.end(); ++i)
       cout<<*i<<" ";

    return 0;
}
