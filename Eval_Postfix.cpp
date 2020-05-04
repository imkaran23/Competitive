/*
#include<bits/stdc++.h>

using namespace std;


void show(stack <string> s)
{
    while (!s.empty())
    {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << endl ;
}

int eval_postfix(string exp)
{
    stack <string> s;
    int x;
    for(int i=0;i<exp.size();i++)
    {
        switch(exp[i])
        {
            case '+' :  x=stoi(s.top());
                        s.pop();
                        x+=stoi(s.top());
                        s.pop();
                        s.push(to_string(x));
                        break;
            case '-' :  x=stoi(s.top());
                        s.pop();
                        x=stoi(s.top())-x;
                        s.pop();
                        s.push(to_string(x));
                        break;
            case '*' :  x=stoi(s.top());
                        s.pop();
                        x*=stoi(s.top());
                        s.pop();
                        s.push(to_string(x));
                        break;
            case '/' :  x=stoi(s.top());
                        s.pop();
                        x=stoi(s.top())/x;
                        s.pop();
                        s.push(to_string(x));
                        break;
            case '^' :  x=stoi(s.top());
                        s.pop();
                        x=pow(stoi(s.top()),x);
                        s.pop();
                        s.push(to_string(x));
                        break;
            default  :  string tmp(1,exp[i]);
                        s.push(tmp);
        }
    }
    return (stoi(s.top())) ;
}

int main()
{
    string postfix = "231*+9-";
    cout<<postfix<<" => Postfix evaluation using stack : " << eval_postfix(postfix)<<endl;
    return 0;
}
*/\
#include<bits/stdc++.h>
using namespace std;
#define max 5

class Stack{
	private:
		int top=-1;
	
	public:
		int stack[max];
		void push(int k);
		int pop();
		void display();
		
};

void Stack::push(int k){
	if(top==max-1){
		cout<<"Stack is Full\n";
	}
	else{
		Stack::top++;
		Stack::stack[Stack::top]=k;
	}
}

int Stack::pop(){
	if(top==-1){
		cout<<"Stack is Empty\n";
		return 0;
	}
	else {
		int x=Stack::stack[top--];
		return x;
	}
}
void Stack::display(){
	int temp=top;
	while(top>=0){
		cout<<Stack::pop()<<"\t";
	}	
	cout<<"\n";
	Stack::top=temp;
}


int main(){
	Stack s;
	cout<<"Enter the expression : ";
	cout<<endl;
	string exp;
	cin>>exp;
	
	for(int i=0;i<exp.size();i++)
	{
		if(exp[i]>=48 && exp[i]<=57){
			s.push(int(exp[i])-48);
		}
		if(exp[i]=='+'){
			int x=s.pop();
			int y=s.pop();
			s.push(x+y);
		}
		
		else if(exp[i]=='-'){
			int x=s.pop();
			int y=s.pop();
			s.push(x-y);
		}
		
		else if(exp[i]=='*'){
			int x=s.pop();
			int y=s.pop();
			s.push(x*y);
		}
		
		else if(exp[i]=='/'){
			int x=s.pop();
			int y=s.pop();
			s.push(x/y);
		}
	}
	cout<<endl<<endl;
	cout<<s.pop()<<endl;
	return 0;
}