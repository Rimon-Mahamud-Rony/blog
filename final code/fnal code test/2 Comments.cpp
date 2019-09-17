#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int number_of_comments = 0; // Initializer
    char ch, single_slash = 47; // ASCII of '/' is 47
    string s; // Empty string

    vector<string> all_comments;

    FILE *file;

    /*If u want to write Something in the file

    cout<<"Write Something in the file"<<endl;

    file = fopen("input.txt", "w");
    while((ch = getchar()) != EOF)
    {
       fputc(ch, file);
    }
    fclose(file);
    */

    file = fopen("comment.txt", "r");

    while((ch = fgetc(file)) != EOF)
    {
        s += ch;
    }

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == single_slash && s[i+1] == single_slash)
        {
            string Comment;
            number_of_comments++;
            i += 2;
            while(s[i] && s[i]!='\n')
            {
                Comment+=s[i];
                i++;
            }
            all_comments.push_back(Comment);
        }
        if(s[i+1] && s[i]==single_slash && s[i+1] == '*')
        {
            string Comment;
            number_of_comments++;
            i += 2;
            while(s[i+1])
            {
                if(s[i] == '*' && s[i+1] == single_slash)
                {
                    i++;
                    break;
                }
                Comment+=s[i];
                i++;
            }
            all_comments.push_back(Comment);
        }
    }

    cout<<"Number of Comments: "<<number_of_comments<<endl;
    int index=1;
    for(auto str : all_comments)cout<<index++<<") "<<str<<endl<<endl;

    return 0;
}
