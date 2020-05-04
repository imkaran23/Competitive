/*
For two given integers n and k find (Zn + Zn-1 - 2Zn-2) mod 10000007, where Zn = Sn + Pn and Sn = 1k + 2k + 3k + … + nk and Pn = 11 + 22 + 33 + … + nn.

Input
There are several test cases (≤ 10000). In each case two space separated positive integers n and k are given.
For last test case n and k are given as 0 0, which is not to be processed.

Constraints
1 < n < 200000000
0 < k < 1000000

Output
For each case print the asked value in separate line.

Example
Input:
10 3
9 31
83 17
5 2
0 0

Output:
4835897
2118762
2285275
3694

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;

    while(scanf("%d%d",&n,&k)){

            if(n || k){
            long long s1,s2,p1,p2,m=10000007;
            long long ans;
            p1=s1=(n-1)%m;
            p2=s2=n%m;

            for( int i=2 ; i<=k ;i++)
            {
                s1 = (s1*((n-1)%m))%m;
                s2 = (s2*(n%m))%m;
            }

            for( int i=2 ; i<=n ;i++)
            {
                p1 = (p1*((n-1)%m))%m;
                p2 = (p2*(n%m))%m;
            }

            ans= ((2*s1)%m + s2 + (2*p1)%m + p2)%m;
            cout<<ans<<endl;

        }
        else
            break;

        }

    return 0;
}
