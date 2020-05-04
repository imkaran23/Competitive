/*
The problem statement is really simple. There are some queries. You are to give the answers.

Input
An integer stating the number of queries Q(equal to 50000), and Q lines follow, each containing one integer K between 1 and 5000000 inclusive.

Output
Q lines with the answer of each query: the Kth prime number.

Example
Input:
7
1
10
100
1000
10000
100000
1000000

Output:
2
29
541
7919
104729
1299709
15485863
*/

#include<bits/stdc++.h>
using namespace std;
vector <bool> v(100000000,true);
int arr[8000000];
int main()
{
    long long int n = 100000000;
    long int i,j ;
    v[1] = false;
    v[0] = false;
    for(i=4;i<=n;i+=2)
     v[i]=false;
    for(i=3;i*i<=n;i+=2)
    {
        if(v[i])
        {
            for(j=i*i;j<=n;j=j+(2*i))
                v[j] = false;
        }
    }
         j=0;
         arr[0] = 2;
         for(i=3;i<=n;i+=2)
          {
            if(v[i])
            arr[++j]=i;
          }
         long long int t;
         cin>>t;
         while(t--)
          {
             long long int n;
             cin>>n;
              cout<<arr[n-1]<<"\n";
          }
            return 0;
      }

