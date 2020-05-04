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
    private:
        Node* head;
    public:
        list();
        ~list();
        bool empty() const;
        const string& front() const;
        void addFront(const string& s);
        void removeFront();
        void reverse();
        // void add(const string& s,int pos);
        // void remove(int pos);
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
    if(head==NULL)
    {
        n->next=n;
        head = n;
    }
    else
    {
        n->next = head;
        Node* tmp = head;
        while(tmp->next!=head)
            tmp=tmp->next;
        tmp->next=n;
        head = n;
    }

}

void list::removeFront()
{
    Node* tmp = head;
    if(tmp==NULL)
        return;
    else if(tmp->next==tmp)
    {
        head=NULL;
        delete tmp->next;
    }
    else
    {
        while(tmp->next!=head)
            tmp=tmp->next;
        tmp->next=head->next;
        tmp=head;
        head=tmp->next;
        delete tmp;
    }


}

void list::reverse()
{
    if(head==NULL||head->next==head)
        return;
    Node *prev,*curr,*nxt;
    prev=head;
    while(prev->next!=head)
            prev=prev->next;
    nxt=NULL;
    curr=head;
    while(true)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        if(curr==head)
            break;
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
        while(true)
        {
            cout<< tmp->element <<"->";
            tmp = tmp->next;
            if(tmp==head)
                break;
        }
    }
}

// void list::add(const string& s,int pos)
// {
//     Node* tmp = head ;
//     for(int i = 0 ; i<pos-1 ; i++ )
//     {
//         if(tmp->next!=NULL)
//             tmp = tmp->next ;
//         else
//         {
//             cout<<"Not possible position !!!\n";
//             return;
//         }
//     }

//     Node* n = new Node;
//     n->element = s;
//     n->next = tmp->next ;
//     tmp->next = n;
// }

// void list::remove(int pos)
// {
//     Node* tmp = head ;
//     for(int i = 0 ; i<pos-1 ; i++ )
//     {
//         if( tmp->next != NULL && tmp->next->next != NULL )
//             tmp = tmp->next ;
//         else
//         {
//             cout<<"Not possible position !!!\n";
//             return;
//         }
//     }

//     Node* n = tmp->next;
//     tmp->next = n->next;
//     delete n;
// }

int main()
{
    list l;
    int ch,pos;
    string item;
    cout<<"\tMENU\n1.ADD FRONT\n2.DELETE FRONT\n3.FRONT ELEMENT\n4.REVERSE\n5.SHOW LIST\n6.EXIT";
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
                cout<<l.front()<<endl;
                break;
            case 4:
                l.reverse();
                break;
            case 5:
                l.show();
                break;
            case 6:
                exit(0);
            default:
                cout<<"Wrong choice !!!\n";
        }

        cout<<"\nEnter your choice : ";
        cin>>ch;
    }while(true);

    return 0 ;
}
