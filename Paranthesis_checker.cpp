#include<bits/stdc++.h>
#include<stack>
using namespace std;

void show(stack <char> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << endl;
}

string Parentheses_Checker(string exp)
{
    stack <char> s;
    char c;
    bool b = true ;
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
        {
            s.push(exp[i]);
            show(s);
        }
        else if(exp[i]==']' || exp[i]=='}' || exp[i]==')')
         {

            if(!s.empty())
            {
                switch(exp[i])
                {
                    case ']' : if(s.top()=='[')
                                s.pop();
                                show(s);
                                break;
                    case '}' : if(s.top()=='{')
                               s.pop();
                               show(s);
                               break;
                    case ')' : if(s.top()=='(')
                               s.pop();
                               show(s);
                               break;
                    default  : b=false;
                }
            }
            else
                b=false;
            }

        if(!b)
            break;
    }

    if(b)
        return exp+" : Parenthesis Matches ";
    else
        return exp+" : Parenthesis doesn't matches !!!";
}

int main()
{
    string exp = "a+[b*{c-((d+e)/f*(g-h))}]]" ;
    cout<<Parentheses_Checker(exp)<<endl;
    return 0 ;
}
