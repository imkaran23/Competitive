#include<iostream>
using namespace std;

class Node
{
    public:
        int coefficient;
        int power;
        Node *next;
        Node()
        {
            coefficient=0;
            power=0;
        }
        friend class poly;
};

class poly
{
    public:
        Node *head;
        poly();
        ~poly();
        bool empty() const;
        void removeFront();
        void addTerm(int c,int p = 0 );
        void show();
        friend void sum(poly& p1,poly& p2);
};

poly::poly()
:head(NULL){}

poly::~poly()
{
    while(!empty())
        removeFront();
}

bool poly::empty() const
{
    return head==NULL;
}

void poly::removeFront()
{
    Node* old = head;
    head = old->next;
    delete old;
}

void poly::addTerm(int c,int p)
{
    Node *n = new Node;
    n->coefficient = c;
    n->power = p;
    n->next = head;
    head = n;
}

void poly::show()
{
    Node* tmp = head ;
    if(tmp==NULL)
        cout<<"List is empty !!!"<<endl;
    else
    {
        while(tmp!=NULL)
        {
            if(tmp->next!=0)
                cout<< tmp->coefficient << 'X' << tmp->power <<'+';
            else
                cout<< tmp->coefficient << 'X' << tmp->power;
            tmp = tmp->next;
        }
        cout<<endl;
    }
}

void Sum(poly& p1,poly& p2)
{
    Node *tmp1 = p1.head;
    Node *tmp2 = p2.head;
    poly p3;
    while(tmp1!=NULL || tmp2!=NULL)
    {
        if(tmp1->power==0 && tmp2==NULL)
        {
            p3.addTerm(tmp1->coefficient);
            tmp1 = tmp1->next;
        }
        else if(tmp2->power==0 && tmp1==NULL)
        {
            p3.addTerm(tmp2->coefficient);
            tmp2 = tmp2->next;
        }
        else if(tmp1->power == tmp2->power)
        {
            p3.addTerm( tmp1->coefficient + tmp2->coefficient,tmp1->power );
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }
        else if(tmp1->power>tmp2->power)
        {
            p3.addTerm(tmp1->coefficient,tmp1->power);
            tmp1 = tmp1->next;
        }
        else if(tmp2->power>tmp1->power)
        {
            p3.addTerm(tmp2->coefficient,tmp2->power);
            tmp2 = tmp2->next;
        }
    }
    cout<<"Polynomial Sum : ";
    p3.show();
    cout<<endl;
}

main()
{
    poly p1,p2;
    p1.addTerm(1);
    p1.addTerm(2,2);
    p1.addTerm(4,4);
    p2.addTerm(2,2);
    p2.addTerm(3,3);
    cout<<"Polynomial 1 : ";
    p1.show();
    cout<<endl;
    cout<<"Polynomial 2 : ";
    p2.show();
    cout<<endl;
    Sum(p1,p2);
    cout<<endl;
}
