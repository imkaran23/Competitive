#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b;
    // cin>>t;
    while(cin>>a>>b){ 
        if(a==0 && b==0) break;
        long long hcf = __gcd(a,b);
        long long lcm = (a*b)/hcf;
        cout<<lcm/hcf<<"\n";
    }
    return 0;
}