#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

void show(queue<int> st)
{
    while (!st.empty())
    {
        cout << ' ' << st.front();
        st.pop();
    }
    cout << endl;
}

void reverse()
{
    if(q.empty())
        return;
    else
    {
        int data = q.front();
        q.pop();
        reverse();
        q.push(data);
    }
    
}

main()
{
    for(int i=1;i<6;i++)
        q.push(i);
    reverse();
    show(q);
}
