#include<iostream>
using namespace std;

class dNode
{
    private:
        string element;
        dNode* previous;
        dNode* next;
    friend class dlist;
};

class dlist
{
    private:
        dNode* head;
        dNode* tail;
    public:
        dlist();
        ~dlist();
        bool empty() const;
        const string& front() const;
        const string& back() const;
        void add(const string& s,int pos=1);
        void remove(int pos=1);
        void show();
};

dlist::dlist()
{
    head = new dNode;
    tail = new dNode;
    head->next = tail;
    //head->previous=NULL;
    tail->previous = head;
    //tail->next = NULL;
}

dlist::~dlist()
{
    while(!empty())
        remove(1);
    delete head;
    delete tail;
}

bool dlist::empty() const
{
    return (head->next == tail);
}

const string& dlist::front() const
{
    return head->next->element;
}

const string& dlist::back() const
{
    return tail->previous->element;
}

void dlist::add(const string& s,int pos)
{
    dNode *tmp = head;
    for(int i=1;i<pos;i++)
        tmp = tmp->next ;
    dNode *n = new dNode;
    n->element=s;
    n->next=tmp->next;
    tmp->next=n;
    n->previous=tmp;
    n->next->previous=n;
}

void dlist::remove(int pos)
{
    dNode *tmp = head->next;
    for(int i=1;i<pos;i++)
        tmp = tmp->next ;
    dNode* u = tmp->previous;
    dNode* w = tmp->next;
    u->next = w;
    w->previous = u;
    delete tmp;

}

void dlist::show()
{
    dNode* tmp=head->next;
    while(tmp!=tail)
    {
        cout<<tmp->element<<" ";
        tmp = tmp->next ;
    }
}

int main()
{
    dlist dl;
    dl.add("1",1);
    dl.add("2",1);
    dl.add("3",1);
    dl.add("4",2);
    dl.add("5",3);
    cout<<dl.front()<<endl;
    cout<<dl.back()<<endl;
    dl.show();
    cout<<endl;
    dl.remove(1);
    dl.remove(2);
    dl.show();
    return 0;
}
