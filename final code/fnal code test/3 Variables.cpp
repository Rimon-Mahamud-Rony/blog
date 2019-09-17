#include <bits/stdc++.h>
using namespace std;

bool reserved(string s)
{
    string S[]=
    {
        "float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct",
        "auto","break","case","char","const","continue","bool",
        "default","do","double","else","enum","extern","while",
        "switch","typedef","union","unsigned","void","volatile",
        "using","namespace","true","false"
    };
    for(auto word  : S)if(word==s)return false;
    return true;
}

bool first_character(char ch)
{
    return ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='_');
}

bool all(string s)
{
    bool ok;
    for(auto ch : s)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||ch=='_'||(ch>='0'&&ch<='9')){}
        else return false;
    }
    return true;
}

int main()
{
    cout<<"Input Variable Name:"<<endl;
    string variable;
    while(getline(cin,variable))
    {
        if(first_character(variable[0])&&all(variable)&&reserved(variable))cout<<"Valid ";
        else cout<<"Not Valid ";
        cout<<"Variable"<<endl;
    }
}
