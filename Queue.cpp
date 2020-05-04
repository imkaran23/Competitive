#include<bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int *q;
    int max,front,rear,count;
public:
    class queue_full{};
    class queue_empty{};
    Queue( int m=5 );
    void enqueue (int x);
    int dequeue ();
    void show();
};

Queue::Queue(int m)
: q(new int[m]),front(0),rear(0),count(0),max(m) {}

void Queue::enqueue(int x)
{
    if(count<max)
    {

        q[rear++]=x;
        count++;
    }
    else
        throw queue_full();
}

int Queue::dequeue()
{
    if(count>0)
    {
        count--;
        return q[front++];
    }
    else
        throw queue_empty();
}

void Queue::show()
{
    if(count>0)
    {
        for(int i= front ; i<rear ; i++)
            cout<<q[i]<<" ";
        cout<<endl;
    }
    else
        throw queue_empty();
}

int main()
{
    int item,ch=1;
    Queue q;

    cout<<"\nQueue Operations using Exception Handling\n";
    cout<<"\n\n\tMENU\n1.ENQUEUE\n2.DEQUEUE\n3.SHOW QUEUE\n4.EXIT\n";
    cout<<"\nEnter your choice : ";
    cin>>ch;

    do
    {
        switch(ch)
        {
        case 1:
            cout<<"\nEnter the item to insert in to the queue : ";
            cin>>item;
            try
            {
                q.enqueue(item);
            }
            catch(Queue::queue_full)  //FULL object is caught
            {
                cout<<"\n***Queue Full***\n";
            }
            break;
        case 2:
            try
            {
                cout<<"\nRemoved Item : "<<q.dequeue();
            }
            catch(Queue::queue_empty) //EMPTY object is caught
            {
                cout<<"\n***Queue Empty***\n";
            }
            break;
        case 3:
                cout<<"\nThe Queue is\n";
            try
            {
                q.show();
            }
            catch(Queue::queue_empty)
            {
                cout<<"\n***Queue Empty***\n";
            }
            break;
        case 4:
            exit(0);
        default:
            cout<<"\nIncorrect option !\n";
        }
        cout<<"\nEnter your choice : ";
        cin>>ch;

    }while(ch<5);

    return 0;
}

