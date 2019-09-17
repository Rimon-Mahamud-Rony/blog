#include <bits/stdc++.h>
using namespace std;

bool flag;
string s;

void check(char ch, int st, int ed)
{
    for(int i=st; i<ed; i++)if(s[i]!=ch){flag=false;return;}
}

int main()
{
    while(getline(cin,s))
    {
        flag=false;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='b')
            {
                flag=true;
                check('a',0,i);
                check('b',i,s.size());
                break;
            }
        }
        cout<<(flag==true?"Acceptable":"Not Acceptable")<<endl;
    }
    return 0;
}
