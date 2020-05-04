/*
PRIME1 - Prime Generator
#number-theory

Peter wants to generate some prime numbers for his cryptosystem. 
Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n 
(1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
typedef long long int ll;


main()
{
    ll n = 100001;
    int a[n]={0};
    vector<int> v;
    a[0]=a[1]=1;

    for(ll i=2; i<=n ; i++)
    {
        if(!a[i])
        {
            v.push_back(i);
            for(ll j=2; j*i<=n ; j++)
            {
                a[j*i] = 1;
            }
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        // int b[n-m+1]={0};
        // for(ll i=0; i<n-m+1 ; i++)
        // {
        //     b[i]=i+m;
        // }

        // for(ll i=0 ;i<v.size() ;i++ )
        // {
        //     for(ll j=0 ; j<n-m+1 ; j++)
        //     {
        //         if(b[j]%v[i]==0)
        //         {
        //             b[j]==0;
        //         }
        //     }
        //     if(v[i]>n/2)
        //         break;
        // }

        // for(ll i=0 ; i<n-m+1 ; i++)
        // {
        //     if(!b[i])
        //     {
        //         for(ll j=2*b[i]-m ; j<n-m+1 ; j+=b[i])
        //         {
        //             b[j]=0;
        //         }
        //     }
        // } 

        // for(ll i=0 ; i<n-m+1 ; i++)
        // {
        //     if(!b[i])
        //         cout<<b[i]<<endl;
        // }     

        bool isPrime[r-l+1];

        for(int i=0;i<r-l;i++){
            isPrime[i]=true;
        }  

        for(int i=0;v[i]*(ll)v[i]<=r;i++){
            int cp = v[i];
            ll base = (l/cp)*cp;
            if(base<l)
                base+=cp;
            for(ll j=base;j<=r;j+=cp){
                isPrime[j-l]=false;
            if(base == cp)
                isPrime[base-l] = true;
            }
        }
        for(int i=0;i<=r-l;i++){
            if(isPrime[i]==true)
                cout<<i+l<<endl;
        }
    }
}