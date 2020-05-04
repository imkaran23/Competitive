#include<iostream>
using namespace std;

class Node
{
    string element;
    Node* next;

    friend class queue;
};

class queue
{
    private:
        Node* rear;
    public:
        queue();
        ~queue();
        bool empty() const;
        const string& front_element() const;
        const string& rear_element() const;
        void enque(const string& s);
        void deque();
        void show();
};

queue::queue()
:rear(NULL){}

queue::~queue()
{
    while(!empty())
        deque();
}

bool queue::empty() const
{
    return rear==NULL;
}

const string& queue::rear_element() const
{
    return rear->element;
}

const string& queue::front_element() const
{
    Node* front=rear;
    while(front->next!=NULL)
        front = front->next;
    return front->element;
}

void queue::enque(const string& s)
{
    Node* n = new Node;
    n->element = s;
    n->next = rear;
    rear = n;
}

void queue::deque()
{
    Node* front=rear;
    if(front->next==NULL)
    {
        rear = front->next;
        delete front;
    }
    else
    {
        while(front->next->next!=NULL)
            front = front->next;
        Node* old = front->next;
        front->next = old->next;
        delete old;
    }
}

void queue::show()
{
    Node* tmp = rear ;
    if(tmp==NULL)
        cout<<"Queue is empty !!!"<<endl;
    else
    {
        while(tmp!=NULL)
        {
            cout<< tmp->element << "->" ;
            tmp = tmp->next;
        }
    }
}

main()
{
    int ch=1;
    string item;
    queue q;
    cout<<"\tMENU\n1.ENQUEUE\n2.DEQUEUE\n3.FRONT ELEMENT\n4.REAR ELEMENT\n5.SHOW QUEUE\n6.EXIT\n";
    cout<<"\nEnter your choice : ";
    cin>>ch;

    do
    {
        switch(ch)
        {
        case 1:
            cout<<"Enter the item to insert in to the queue : ";
            cin>>item;
            q.enque(item);
            break;
        case 2:
            q.deque();
            break;
        case 3:
            cout<<q.front_element()<<endl;
            break;
        case 4:
            cout<<q.rear_element()<<endl;
            break;
        case 5:
            q.show();
            break;
        case 6:
            exit(0);
        default:
            cout<<"\nIncorrect option !\n";
        }
        cout<<"\nEnter your choice : ";
        cin>>ch;

    }while(true);

}
