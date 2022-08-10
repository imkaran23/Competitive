#include<bits/stdc++.h>
using namespace std;
// #define ll long long;
#define ll long long int
const ll mod = 1e9+7;

vector<vector<int>> g;
vector<ll> dp;
int n, m;

ll recur(int i){
    if(i==n) return 1;
    if(dp[i]!=-1) return dp[i];

    int tmp = 0;
    for(auto x : g[i]){
        tmp += recur(x);
        tmp %=mod ;
    }

    return dp[i] = tmp;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    g.resize(n+1);
    dp.resize(n+1, -1);

    while(m--){
        int a,b; 
        cin >> a >> b;
        g[a].push_back(b);
    }

    cout<< recur(1) <<'\n';

    return 0;
}