#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long n,k,s1,s2,hcf,i;
    while(cin>>n>>k && n != -1 && k != -1)
    {
        s2 = 0;
        for(i=3; i<=k; i++){
            if(i%2) s2 += i/2;
            else s2 += i/2 - 1;
        }

        if(s2==0) cout<<0<<"\n";
        else {
            s1 = n*(n-1)/2;
            hcf = __gcd(s1,s2);
            s1/=hcf;
            s2/=hcf;
            cout<<s2<<"/"<<s1<<"\n";
        }
    }
    return 0;
}