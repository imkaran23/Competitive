#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lli pair<ll, int>
const ll mod = 1e9+7;
 
vector<vector<pair<int, int>>> g;
vector<int> vis;
int n, m;
 
void djikstra(int s){
    priority_queue<lli, vector<lli>, greater<lli>> pq;
 
    vector<vector<ll>> ans(n+1);
    for(int i=1; i<=n; i++) ans[i] = {(ll)1e18, 0, INT_MAX, 0};
 
    ans[s] = {0, 1, 0, 0};
    pq.push({0, s});
 
    while(!pq.empty()){
        int u = pq.top().second;
        // ll w = pq.top().first;
        pq.pop();
 
        if(vis[u]) continue;
        vis[u] = 1;
 
        for(auto x : g[u]){
            int v = x.first;
            ll weight = x.second;
 
            if(ans[v][0] > ans[u][0] + weight){
                ans[v][0] = ans[u][0] + weight;
                ans[v][1] = ans[u][1];
                // yaha pe min max ni lena tha !!!!!!!!!! FFFFFFFFFFFFFFFFFFFFF
                ans[v][2] = ans[u][2] + 1;
                ans[v][3] = ans[u][3] + 1;
 
                pq.push({ans[v][0], v});
            }
            else if(ans[v][0] == ans[u][0] + weight){
                ans[v][1] = (ans[v][1] + ans[u][1])%mod;
                ans[v][2] = min(ans[v][2], ans[u][2] + 1);
                ans[v][3] = max(ans[v][3], ans[u][3] + 1);
            }
        }
    }
 
    cout<<ans[n][0]<<' '<<ans[n][1]<<' '<<ans[n][2]<<' '<<ans[n][3]<<'\n';
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    g.resize(n+1);
 
    while(m--){
        int a,b,c; 
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        // g[b].push_back({a,c});
    }
 
    vis.assign(n+1,0);
    djikstra(1);
    return 0;
}
