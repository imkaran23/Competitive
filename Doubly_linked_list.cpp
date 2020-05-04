#include<iostream>
using namespace std;

typedef string Elem;        // list element type

class DNode {               // doubly linked list node
private:
    Elem elem;              // node element value
    DNode* prev;            // previous node in list
    DNode* next;            // next node in list
friend class DLinkedList;   // allow DLinkedList access
};

class DLinkedList
{
    public:
        DLinkedList();                  // constructor
        ~DLinkedList();                 // destructor
        bool empty() const;             // is list empty?
        const Elem& front() const;      // get front element
        const Elem& back() const;       // get back element
        void addFront(const Elem& e);   // add to front of list
        void addBack(const Elem& e);    // add to back of list
        void removeFront();             // remove from front
        void removeBack();              // remove from back
        void show();                    // show elements of lists
    private:
        DNode* header;                  // list sentinels
        DNode* trailer;
    protected:                          // local utilities
        void add(DNode* v, const Elem& e);  // insert new node after v
        void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList()
{
    header = new DNode;     // create sentinels
    trailer = new DNode;
    header->next = trailer; // have them point to each other
    trailer->prev = header;
}

DLinkedList::~DLinkedList()
{
    while (!empty()) removeFront(); // remove all but sentinels
    // delete header;                  // remove the sentinels
    // delete trailer;
}

bool DLinkedList::empty() const     // is list empty?
{ return (header->next == trailer); }

const Elem& DLinkedList::front() const // get front element
{ return header->next->elem; }

const Elem& DLinkedList::back() const  // get back element
{ return trailer->prev->elem; }

void DLinkedList::add(DNode* v, const Elem& e)
{
    DNode* u = new DNode;
    u->elem = e;                        // create a new node for e
    u->next = v;                        // link u in between v
    u->prev = v->prev;                  // . . .and v->prev
    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(const Elem& e) // add to front of list
{ add(header->next, e); }

void DLinkedList::addBack(const Elem& e) // add to back of list
{ add(trailer, e); }

void DLinkedList::remove(DNode* v)
{
    DNode* u = v->prev; // predecessor
    DNode* w = v->next; // successor
    u->next = w;        // unlink v from list
    w->prev = u;
    delete v;
}

void DLinkedList::removeFront() // remove from font
{ remove(header->next); }

void DLinkedList::removeBack() // remove from back
{ remove(trailer->prev); }

void DLinkedList::show()
{
    DNode* tmp = header ;
    while(tmp != trailer)
    {
        cout<<tmp->next->elem<<" ";
        tmp = tmp->next ;
    }
}

main()
{
    DLinkedList l;
    int ch,pos;
    string item;
    cout<<"\tMENU\n1.ADD FRONT\n2.DELETE FRONT\n3.ADD BACK\n4.REMOVE BACK\n5.SHOW FRONT\n6.SHOW BACK\n7.SHOW LIST\n8.EXIT";
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
                l.addBack(item);
                break;
            case 4:
                l.removeBack();
                break;
            case 5:
                cout<<l.front()<<endl;
                break;
            case 6:
                cout<<l.back()<<endl;
                break;
            case 7:
                l.show();
                break;
            case 8:
                exit(0);
            default:
                cout<<"Wrong choice !!!\n";
        }

        cout<<"\nEnter your choice : ";
        cin>>ch;
    }while(true);

}

