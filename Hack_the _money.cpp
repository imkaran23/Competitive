/*
Hack the money
Attempted by: 722/Accuracy: 35%/Maximum Score: 20/
 19 Votes
Tag(s): No tags
PROBLEM
 
EDITORIAL
 
MY SUBMISSIONS
You are a bank account hacker.Initially you have 1 rupee in your account, and you want exactly N rupees in your account.You wrote two hacks, First hack can multiply the amount of money you own by 10, while the second can multiply it by 20. These hacks can be used any number of time . Can you achieve the desired amount N using these hacks.
Constraints:

1<=T<=100

1<=N<=10^12

Input ->

The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.The first and only line of each test case contains a single integer N.  
 Output ->For each test case, print a single line containing the string "Yes" if you can make exactly N rupees or "No" otherwise.

SAMPLE INPUT 
5
1
2
10
25
200
SAMPLE OUTPUT 
Yes
No
Yes
No
Yes
Explanation
In the last case hacker can get Rs. 200 by first using 10x hack and then using 20x hack once.

1 -> 10 -> 200

 

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB


#include<iostream>
#include<string>
using namespace std;

main()
{
    int t,i;
    long long int x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        if( x==1 )
        {
            cout<<"Yes"<<endl;
        }
        else if ( x<10 )
        {
            cout<<"No"<<endl;
        }
        else
        {   
            i = 0;
            string s  = to_string(x);
            // cout<<"STRING : "<<s<<endl;
            size_t pos = s.find('0');
            // cout<<"POS : "<<pos<<endl;
            //if( pos!= std::npos)
            string s1 = s.substr(0,pos);
            string s2 = s.substr(pos,s.size()-sizeof(s1));
            cout<<"STRING 1 : "<<s1<<" STRING 2 : "<<s2<<endl;
            x = stoi(s);
            // cout<<"NUMBER : "<<x<<endl;
            while(true)
            {
                if( x == (1<<i) && i == sizeof(s2))
                {
                    cout<<"Yes"<<endl;
                    break;
                }
                else if ( (1<<i) > x )
                {
                    cout<<"No"<<endl;
                    break;
                }
                i++;
            }
        } 
    }
}
*/

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
vector <int> v;

bool binarySearch(int key,int low=0,int high=v.size())
{
   sort(v.begin(),v.end());
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(v[mid]<key)
     {
         low=mid+1;
     }
     else if(v[mid]>key)
     {
         high=mid-1;
     }
     else
     {
         return true;
     }
   }
   return false;                
 } 

void recur(long long int a)
{
    if(a > 1000000000000)
        return;
    else
    {
        long long int b = a*10;
        long long int c = a*20;
        if(!binarySearch(b))
            v.push_back(b);
        if(!binarySearch(c))
            v.push_back(c);
        recur(b);
        recur(c);
        // long long int b = a*20;
        // if(!binarySearch(b))
        //     v.push_back(b);
        // recur(b);
    }
    
}

void htm(long long int x)
{
    for ( int i=0 ; i< v.size() ; i++)
    {
        if(v[i]==x)
        {
            cout<<"Yes\n";
            return;
        }
    }

    cout<<"No\n";
    return;
}

main()
{
    int t,i;
    long long int x;
    cin>>t;

    v.push_back(1);
    recur(1);

    while(t--)
    {
        cin>>x;
        htm(x);
    }
}

/*
#include<stdio.h>
int myfunc(int n)
{
    if(n==1)
        return 1;
    if(n%10==0)
        if(myfunc(n/10)==1)
            return 1;
    if(n%20==0)
        if(myfunc(n/20)==1)
            return 1;
    return 0;
        
}
void main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int x=myfunc(n);
        if(x)
        printf("Yes\n");
        else
        printf("No\n");
    }
}
*/