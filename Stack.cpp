#include<bits/stdc++.h>
using namespace std;

class ArrayStack
{
private:
    int t,capacity;
    int *a;
public:
    class Stack_full{};
    class Stack_empty{};
    ArrayStack(int cap = 5);
    bool empty();
    int size();
    int top() ;
    void push(int x) ;
    int pop() ;
    void show();
};

ArrayStack::ArrayStack( int cap )
: a( new int[cap]),t(-1),capacity(cap){};

bool ArrayStack::empty()
{
    return (t<0);
}

int ArrayStack::size()
{
    return t+1 ;
}

int ArrayStack::top()
{
    if(empty())
        throw Stack_empty();
    return a[t];
}

void ArrayStack::push(int x)
{
    if( size() == capacity )
        throw Stack_full();
    a[++t]=x;
}

int ArrayStack::pop()
{
    if(empty())
        throw Stack_empty();
    return a[t--];
}

void ArrayStack::show()
{
    for(int i=0 ; i<size() ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int item,ch;
    ArrayStack s;
    cout<<"\nStack with Exception Handling";
    cout<<"\n\n\tMENU\n1.PUSH\n2.POP\n3.SHOW STACK\n4.EXIT";
    cout<<"\nEnter your choice : ";
    cin>>ch;
    do
    {
        switch(ch)
        {
            case 1:
                cout<<"Enter the item to push : ";
                cin>>item;
                try
                {
                    s.push(item);
                }
                catch(ArrayStack::Stack_full)
                {
                    cout<<"\n***Stack Overflow***\n";
                }
                break;
            case 2:
                try
                {
                    cout<<"\nPoped Item is : "<<s.pop();
                }
                catch(ArrayStack::Stack_empty)
                {
                    cout<<"\n***Stack Empty***\n";
                }
                break;
            case 3:
                cout<<"\nThe Stack is : \n";
                try
                {       s.show();    }
                    catch(ArrayStack::Stack_empty)
                {
                    cout<<"\n***Stack Empty***\n";
                }
                break;
            case 4:
                exit(0);
        }

        cout<<"\nEnter your choice : ";
        cin>>ch;
    }while(true);

    return 0;
}
