/*
Converting
Attempted by: 541/Accuracy: 13%/Maximum Score: 20/
 18 Votes
Tag(s): Easy
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
You are given a,b and c.You need to convert a to b.
You can perform following operations :-
1) Multiply a by c.
2) Decrease a by 2.
3) Decrease a by 1.
You can perform this operation in any order and any number of times.
You need to find and print minimum number of steps to convert a to b.

Constraints :-



Input : -

First line contains nuber of test cases.

Next  line for contains three space separated integer  .

Output : -

Print minimum no. of steps as output in new line for each test case.

SAMPLE INPUT 
2
3 10 2
11 6 2
SAMPLE OUTPUT 
3
3
Explanation
For test case : -

1) First multple  with  then

2) Subtract  from  to get 

3) Multiple  with   to get .

So, 3 steps.

For test case : -

1) Subtact  from  , 2 times

2) Subtract  from 7.

So, 3 steps.

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include<iostream>
using namespace std;
int steps;
void recur(int a,int b,int c)
{
    if(a==b)
    {
        steps++;
        return;
    }
    if(a-2>b)
    {
        return;
    }
    recur(a*c,b,c);
    recur(a-2,b,c);
    recur(a-1,b,c);
}

main()
{
    int t,a,b,c;
    cin>>t;
    while(t--)
    {   
        steps=0;
        cin>>a>>b>>c;
        recur(a,b,c);
        cout<<steps<<endl;
    }
}


/*
#include<iostream>
using namespace std;
int count=0;
long long  fun( long a, long b, long c){
    //count++;
    if(a==b)
    return 0;
   
   if(a>b){
       return (a-b+1)/2 ;
   }
   else
   {
       if(b%c == 0)
        return 1+fun(a,b/c,c);
       else
       {
           int diff = c-(b%c);
           return (diff+1)/2+fun(a,b+diff,c);
       }
   }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        cout<<fun(a,b,c)<<endl;
    }
}
*/