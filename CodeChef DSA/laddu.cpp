#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int numberOfActivity;
        string ethnic;
        cin>>numberOfActivity>>ethnic;
        int laddu=0;
        while(numberOfActivity--)
        {
            string activity;
            cin>>activity;
            if(activity == "CONTEST_WON")
            {
                int rank;
                cin>>rank;
                if(rank <= 20)
                    laddu+= 300 + (20-rank);
                else
                    laddu+= 300;
            }
            else if(activity == "TOP_CONTRIBUTOR")
            {
                laddu+= 300;
            }
            else if(activity == "BUG_FOUND")
            {
                int severity;
                cin>>severity;
                laddu+= severity;
            }
            else if(activity == "CONTEST_HOSTED")
                laddu+= 50;
            else
                continue;
        }
        if(ethnic == "INDIAN")
            cout<<(laddu/200)<<endl;
        else
            cout<<(laddu/400)<<endl;
    }
    return 0;
}
