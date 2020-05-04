/*
Divide Number
Attempted by: 2306/Accuracy: 64%/Maximum Score: 30/
 35 Votes
Tag(s): Algorithms, DFS, Medium, String
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Given integer , you need to find four integers , such that they're all factors of  (), and . Your goal is to maximize .

Input format
First line contains an integer , represents the number of test cases.

Each of the next  lines contains an integer  (,  will not exceed 64 bit integer).

Output format
 lines, each line contains the answer () to correspond test case. If there is no way to find such four numbers, output .

SAMPLE INPUT 
1
8
SAMPLE OUTPUT 
16
Explanation

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
#define lli long long int
int a[20000];

int f(int n,int k)
{
    if(n==0 and k==0) 
        return 1;
    if((n==0 and k!=0) || (n!=0 and k==0)) 
        return -1;

    lli ans = -1;

    for(int factor: a)
    {
        if(factor <= n)
        {
            lli subproblem = f(n - factor, k - 1);
            if (subproblem != -1)
                ans = max(ans, subproblem * factor);
        }
    } 
    return ans;
}

main()
{
    int t,n,k;
    cin>>t;
    while (t--)
    {
        k=0;
        cin>>n;
        memset(a,0,20000*sizeof(a[0]));
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                a[k]=0;
                k++;
            }
        }

        cout<<f(n,4)<<endl;
    }
    
}