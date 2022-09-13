#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        long long a[n];
        for(int i=0; i<n; i++) a[i] = s[i] - '0';

        for(int i=1; i<n; i++) a[i] += a[i-1];

        map<long long, long long> mp;
        mp[0] = 1;
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long x = a[i] - i - 1; // -1 ku kiya aaj tak ni samagh aaya
            ans += mp[x];
            // cout<<i<<' '<<ans<<' ';
            mp[x]++;
        }

        cout<<ans<<'\n';
        
    }

    return 0;
}