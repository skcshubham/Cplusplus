#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int counter[26]= {0};
        string s;
        cin>>s;
        int len;
        len=s.length();
        string s1,s2;
        s1= s.substr(0,len/2);
        s2= s.substr(((len + 1) / 2));
        cout<<s1<<" "<<s2;
        bool lapindrome= true;
        for(int i=0; i<s1.length(); i++)
        {
            counter[s1[i]-'a']++;
            counter[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++)
        {
            cout<<counter[i]<<" ";
            if(counter[i] != 0)
                lapindrome= false;
        }
        if(lapindrome == true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
