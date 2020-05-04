#include<stdio.h>
#include<cstring>
#include<stack>
using namespace std;

struct node
{
    char value;
    node *left,*right;
};

node* newNode(char c)
{
    node *tmp = new node;
    tmp->left=tmp->right = NULL;
    tmp->value = c;
    return tmp;
}

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

node* createBT(char postfix[])
{
    stack<node*> s;
    node *t;

    for(int i=0; i<strlen(postfix); i++)
    {
        if(!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            s.push(t);
        }
        else
        {
            t = newNode(postfix[i]);

            t->left = s.top();
            s.pop();
            t->right = s.top();
            s.pop();

            s.push(t);
        }
        
    }

    t = s.top();
    s.pop();
    return t;
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%c ", root->value);
        inorder(root->right);
    }
}

void preorder(node* root)
{
    if(root!=NULL)
    {
        printf("%c ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

main()
{
    char postfix[] = "ab+ef*g*-";
    node* BT = createBT(postfix);
    printf("infix expression is \n"); 
    inorder(BT); 
    printf("\n");
    printf("prefix expression is \n"); 
    preorder(BT); 
}