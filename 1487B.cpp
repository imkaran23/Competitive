#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        long long n,k;
        cin>>n>>k;
        if(n%2==0) cout<<(k-1)%n + 1<<"\n";
        else{
            long long y = n/2;
            k += k/y - (k%y==0?1:0);
            cout<<(k-1)%n + 1<<"\n";
        }
        
    }
}