#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

void show(stack<int> st)
{
    while (!st.empty())
    {
        cout << ' ' << st.top();
        st.pop();
    }
    cout << endl;
}

void insert_at_bottom(int temp)
{
    if(s.empty())
        s.push(temp);
    else
    {
        int x = s.top();
        s.pop();
        insert_at_bottom(temp);
        s.push(x);
    }
}

void reverse()
{
    if(!s.empty())
    {
        int temp = s.top();
        s.pop();
        reverse();

        insert_at_bottom(temp);
    }
}

main()
{
    for(int i=1;i<6;i++)
        s.push(i);
    reverse();
    show(s);
}
