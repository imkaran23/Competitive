#include<iostream>
using namespace std;

class Node
{
    string element;
    Node* next;

    friend class list;
};

class list
{
    public:
        Node* head;
        list();
        ~list();
        bool empty() const;
        const string& front() const;
        void addFront(const string& s);
        void removeFront();
        void add(const string& s,int pos);
        void remove(int pos);
        void reverse();
        void show();
};

list::list()
:head(NULL){}

list::~list()
{
    while(!empty())
        removeFront();
}

bool list::empty() const
{
    return head==NULL;
}

const string& list::front() const
{
    return head->element;
}

void list::addFront(const string& s)
{
    Node* n = new Node;
    n->element = s;
    n->next = head;
    head = n;
}

void list::removeFront()
{
    Node* old = head;
    head = old->next;
    delete old;
}

void list::reverse()
{
    Node *prev,*curr,*nxt;
    prev=NULL;
    nxt=NULL;
    curr=head;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
}

void list::show()
{
    Node* tmp = head ;
    if(tmp==NULL)
        cout<<"List is empty !!!"<<endl;
    else
    {
        while(tmp!=NULL)
        {
            if(tmp->next!=NULL)
                cout<< tmp->element << "->" ;
            else
                cout<< tmp->element ;

            tmp = tmp->next;
        }
    }
}

void list::add(const string& s,int pos)
{
    Node* tmp = head ;
    for(int i = 0 ; i<pos-1 ; i++ )
    {
        if(tmp->next!=NULL)
            tmp = tmp->next ;
        else
        {
            cout<<"Not possible position !!!\n";
            return;
        }
    }

    Node* n = new Node;
    n->element = s;
    n->next = tmp->next ;
    tmp->next = n;
}

void list::remove(int pos)
{
    Node* tmp = head ;
    for(int i = 0 ; i<pos-1 ; i++ )
    {
        if( tmp->next != NULL && tmp->next->next != NULL )
            tmp = tmp->next ;
        else
        {
            cout<<"Not possible position !!!\n";
            return;
        }
    }

    Node* n = tmp->next;
    tmp->next = n->next;
    delete n;
}

int main()
{
    list l;
    int ch,pos;
    string item;
    cout<<"\tMENU\n1.ADD FRONT\n2.DELETE FRONT\n3.ADD AT ANY POSITION\n4.REMOVE AT ANY POSITION\n5.SHOW LIST\n6.REVERSE\n7.EXIT";
    cout<<"\nEnter your choice : ";
    cin>>ch;
    do
    {
        switch(ch)
        {
            case 1:
                cout<<"Enter the string to add from front : ";
                cin>>item;
                l.addFront(item);
                break;
            case 2:
                l.removeFront();
                break;
            case 3:
                cout<<"Enter the string to add from front : ";
                cin>>item;
                cout<<"Enter the position to add from front : ";
                cin>>pos;
                l.add(item,pos);
                break;
            case 4:
                cout<<"Enter the position to remove from front : ";
                cin>>pos;
                l.remove(pos);
                break;
            case 5:
                l.show();
                break;
            case 6:
                l.reverse();
                break;
            case 7:
                exit(0);
            default:
                cout<<"Wrong choice !!!\n";
        }

        cout<<"\nEnter your choice : ";
        cin>>ch;
    }while(true);

    return 0 ;
}
