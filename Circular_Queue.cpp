#include<bits/stdc++.h>
using namespace std;

class CircularQueue
{
private:
    int *q;
    int max,front,rear,count;
public:
    class queue_full{};
    class queue_empty{};
    CircularQueue( int m=3 );
    void enqueue (int x);
    int dequeue ();
    void show();
};

CircularQueue::CircularQueue(int m)
: q(new int[m]),front(0),rear(0),count(0),max(m) {}

void CircularQueue::enqueue(int x)
{
    if(count<max)
    {

        q[rear%max]=x;
        rear++;
        count++;
    }
    else
        throw queue_full();
}

int CircularQueue::dequeue()
{
    if(count>0)
    {
        count--;
        front++;
        return q[(front-1)%max];
    }
    else
        throw queue_empty();
}

void CircularQueue::show()
{
    if(count>0)
    {
        if(rear-1<max)
        {
            for(int i= front ; i<rear ; i++)
            cout<<q[i]<<" ";
        }
        else
        {
            for(int i= front ; i<max ; i++)
            cout<<q[i]<<" ";
            for(int i= 0 ; i< rear%max ; i++)
                cout<<q[i]<<" ";
            cout<<endl;
        }
    }
    else
        throw queue_empty();
}

int main()
{
    int item,ch=1;
    CircularQueue q;

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
            catch(CircularQueue::queue_full)  //FULL object is caught
            {
                cout<<"\n***Queue Full***\n";
            }
            break;
        case 2:
            try
            {
                cout<<"\nRemoved Item : "<<q.dequeue();
            }
            catch(CircularQueue::queue_empty) //EMPTY object is caught
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
            catch(CircularQueue::queue_empty)
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

