#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        long long int n,x,sum=0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin>>x;
            sum+=x;
            sum%=n;
        }
 
        if(sum%n) cout<<"NO\n";
        else cout<<"YES\n";
    }
} 