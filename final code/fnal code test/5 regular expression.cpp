#include <bits/stdc++.h>
using namespace std;

string s;

bool check()
{
    int state=1;
    for(auto ch : s)
    {
        if(ch=='a')
        {
            if(state==1)state=2;
            else if(state==2)state=2;
            else if(state==3)state=2;
            else if(state==4)state=5;
            else if(state==5)state=2;
        }
        if(ch=='b')
        {
            if(state==1)state=2;
            else if(state==2)state=3;
            else if(state==3)state=4;
            else if(state==4)state=4;
            else if(state==5)state=4;
        }
    }
    return state==4;
}

int main()
{
    while(getline(cin,s))
    {
        cout<<(check()?"Acceptable":"Not Acceptable")<<endl;
    }
    return 0;
}
