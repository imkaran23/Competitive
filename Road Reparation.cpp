#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lli pair<ll, int>
const ll mod = 1e9+7;

vector<vector<pair<int, int>>> g;
vector<int> vis;
int n, m, nodes;

void dfs(int i, int par){
    if(vis[i]) return;
    vis[i] = 1;
    nodes++;

    for(auto v : g[i]){
        int x = v.first;
        if(x == par) continue;
        dfs(x, i);
    }
}

ll prim(int source){

    ll ans = 0;
    vector<ll> inSet(n+1, 0), dist(n+1, INT_MAX);
    priority_queue<lli, vector<lli>, greater<lli>> pq;
    dist[source] = 0;
    pq.push({0,source});

    while(!pq.empty()){
        int u = pq.top().second;
        ll tmp = pq.top().first;
        pq.pop();

        if(inSet[u]) continue;
        inSet[u] = 1;
        ans += tmp;

        for(auto x : g[u]){
            int v = x.first;
            ll w = x.second;

            if(inSet[v]==0 && dist[v]>w){
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }

    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);

    while(m--){
        int a,b,c; 
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    nodes = 0;
    dfs(1, -1);

    if(nodes!=n) cout<<"IMPOSSIBLE\n";
    else{
        cout<< prim(1) <<'\n';
    } 

    return 0;
}