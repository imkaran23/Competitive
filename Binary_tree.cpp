#include<iostream>
using namespace std;

class dNode
{
    private:
        int element;
        dNode* left;
        dNode* right;
    friend class Binary_tree;
    friend void inorder(dNode* tmp);
    friend void preorder(dNode* tmp);
    friend void postorder(dNode* tmp);

};

class Binary_tree
{
    public:
        dNode* root;
        Binary_tree();
        void root_element();
        void add(int s);
        friend void inorder(dNode* tmp);
        friend void preorder(dNode* tmp);
        friend void postorder(dNode* tmp);
};

Binary_tree::Binary_tree()
:root(NULL){}

void Binary_tree::root_element()
{
    cout<<"Root element :"<<(root->element)<<endl;
    cout<<"Root's right element :"<<(root->right->element)<<endl;
    cout<<"Root's left element :"<<(root->left->element)<<endl;
}

void Binary_tree::add(int s)
{
    dNode* tmp = root;
    dNode* prev = root;
    if(tmp==NULL)
    {
        dNode* n = new dNode;
        n->right = NULL;
        n->left = NULL;
        n->element = s;
        root = n;
        cout<<"First Node added successfully \n";
    }
    else
    {
        while(tmp!=NULL)
        {
            if(s>(tmp->element))
            {
                cout<<"Found position "<<tmp->element<<" right\n";
                prev = tmp;
                tmp=tmp->right;
            }
            else if (s<(tmp->element))
            {
                cout<<"Found position "<<tmp->element<<" left\n";
                prev = tmp;
                tmp=tmp->left;
            }
        }

        if(s<prev->element)
        {
            dNode* n = new dNode;
            n->right = NULL;
            n->left = NULL;
            n->element = s;
            prev->left = n;
            cout<<"Node added successfully\n";
        }
        else
        {
            dNode* n = new dNode;
            n->right = NULL;
            n->left = NULL;
            n->element = s;
            prev->right = n;
            cout<<"Node added successfully\n";
        }
    }
}

void inorder(dNode* tmp)
{
    if(tmp==NULL)
        return;
    inorder(tmp->left);
    cout<<tmp->element<<" ";
    inorder(tmp->right);
}

void preorder(dNode* tmp)
{
    if(tmp==NULL)
        return;
    cout<<tmp->element<<" ";
    preorder(tmp->left);
    preorder(tmp->right);
}

void postorder(dNode* tmp)
{
    if(tmp==NULL)
        return;
    postorder(tmp->left);
    postorder(tmp->right);
    cout<<tmp->element<<" ";
}

main()
{
    Binary_tree obj;
    obj.add(4);
    obj.add(2);
    obj.add(5);
    obj.add(1);
    obj.add(3);
    obj.root_element();
    cout<<"Inorder traversal \n";
    inorder(obj.root);
    cout<<endl;
    cout<<"Preorder traversal \n";
    preorder(obj.root);
    cout<<endl;
    cout<<"Postorder traversal \n";
    postorder(obj.root);
    cout<<endl;
}
