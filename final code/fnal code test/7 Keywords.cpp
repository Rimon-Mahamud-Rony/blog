#include "bits/stdc++.h"
using namespace std;

bool isKeyword(string Word)
{
    string s[]=
    {
        "float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct",
        "auto","break","case","char","const","continue","bool",
        "default","do","double","else","enum","extern","while",
        "switch","typedef","union","unsigned","void","volatile",
        "using","namespace","true","false"
    };
    for(auto word : s)if(word==Word)return true;
    return false;
}

bool isChar(char ch)
{
    return (ch>='a' && ch<='z');
}

int main()
{
    char ch;
    string s;
    FILE *file;

    file = fopen("key.txt","r");

    while((ch=getc(file)) != EOF)
    {
        s += ch;
    }

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='/' && s[i+1]=='/')
        {
            i+=2;
            while(s[i]!='\n')i++;
        }
        if(s[i]=='/' && s[i+1]=='*')
        {
            i+=2;
            while(s[i]!='*' && s[i+1]!='/')i++;
        }
        if(isChar(s[i]))
        {
            string Word;
            Word+=s[i++];
            while(true)
            {
                if(isChar(s[i]))Word+=s[i++];
                else break;
            }
            if(isKeyword(Word))cout<<Word<<endl;
        }
    }

    return 0;
}
