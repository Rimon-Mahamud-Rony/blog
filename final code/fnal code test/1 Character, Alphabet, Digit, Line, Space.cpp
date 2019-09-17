#include <bits/stdc++.h>
using namespace std;

bool alpha(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

bool num(char ch)
{
    return (ch>='0' && ch<='9');
}

void print(string s, int n)
{
    cout<<"Number of "<<s<<" = "<<n<<endl;
}

int alphabet,digit,line,space;

int main ()
{
    string s;
    char ch;

    FILE *file;

    file = fopen("character.txt", "r");

    while((ch = fgetc(file)) != EOF)
    {
        s += ch;
    }

    for(auto S : s)
    {
        if(alpha(S))alphabet++;
        if(num(S))digit++;
        if(S==' ')space++;
        if(S=='\n')line++;
    }

    print("Characters",s.size());
    print("Alphabets",alphabet);
    print("Digits",digit);
    print("Spaces",space);
    print("Lines",line);

    return 0;
}
