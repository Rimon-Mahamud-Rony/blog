#include <bits/stdc++.h>
using namespace std;

string expression;

void show()
{
    cout<<"expression : ";
    for(int i=0; i<expression.size(); i++)
    {
        if(i<9)cout<<" "<<expression[i];
        else cout<<"  "<<expression[i];
    }
    cout<<endl;
    cout<<"position   : ";
    for(int i=1; i<=expression.size(); i++)cout<<" "<<i;
    cout<<endl;
}

void print(vector<pair<char,int> > v)
{
    for(auto pr : v)cout<<pr.first<<" on position "<<pr.second<<endl;
    v.clear();
}

int precedence(int start_index)
{
    vector<pair<char,int> > add_sub,mul_div;
    for(int i=start_index; i<expression.size(); i++)
    {
        if(expression[i]=='(')i=precedence(i+1);
        else if(expression[i]=='+' || expression[i]=='-')add_sub.push_back({expression[i],i+1});
        else if(expression[i]=='*' || expression[i]=='/')mul_div.push_back({expression[i],i+1});
        else if(expression[i]==')')
        {
            print(mul_div);
            print(add_sub);
            return i;
        }
    }
    print(mul_div);
    print(add_sub);
}

int main()
{
    while(getline(cin,expression))
    {
        show();
        precedence(0);
    }

    return 0;
}
