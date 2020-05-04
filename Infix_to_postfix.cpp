#include<bits/stdc++.h>
//#include<stack>
using namespace std;
//using std::string;

void show(stack <char> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << endl;
}

int presedence(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

string infix_to_postfix(string infix)
{
   stack <char> s;
   string postfix;
   for(int i=0;i<infix.size();i++)
   {
        if((infix[i] >= 'a' && infix[i] <= 'z')||(infix[i] >= 'A' && infix[i] <= 'Z'))
            postfix+=infix[i];
        else if(infix[i]=='(')
            s.push(infix[i]);
        else if(infix[i]==')')
        {
            while(s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(!s.empty())
        {
            if(infix[i]==s.top())
                postfix+=s.top();
            else if(presedence(infix[i])>presedence(s.top()))
                    s.push(infix[i]);
            else //if(presedence(infix[i])<=presedence(s.top()))
            {
                while( !s.empty() && presedence(infix[i])<=presedence(s.top()) )
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
        else
            s.push(infix[i]);

        show(s);
   }

   while(!s.empty())
   {
       postfix+=s.top();
       s.pop();
   }

   return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    infix = "a+b*c/d-g+f";
    cout<<infix<<":"<<infix_to_postfix(infix)<<endl;
    return 0 ;
}
