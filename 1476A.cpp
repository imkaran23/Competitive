#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){ 
        double n,k;
        cin>>n>>k;
        long long int ans = ceil((k*ceil(n/k))/n) ;
        cout<<ans<<"\n";
    }
}