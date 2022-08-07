#include <bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll, ll> mp;
vector<ll> a(5001,0);
ll ans,n,m;

ll dp[5001][5001];

ll recur(int idx, int c, ll tmp){
    if(idx == n+1) return 0;

    if(dp[idx][c]!=-1) return dp[idx][c];

    ll z = 0;
    z = tmp + a[idx];
    if(mp.find(c+1)!=mp.end())
        z += mp[c+1];
    
    ans = max(ans, max(tmp,z));

    ll x = recur(idx+1, c+1, z);
    ll y = recur(idx+1, 0, tmp);

    return dp[idx][c] = max(x,y);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;

    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        mp[a] = b;
    }
    
    ans = 0;
    memset(dp, -1, sizeof(dp));
    recur(1, 0, 0);

    cout<<ans<<'\n';
    return 0;
}