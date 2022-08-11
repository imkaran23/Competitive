#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g, rg;
vector<int> vis, top, component, ans;

void topo(int u){
    vis[u] = 1;

    for(int v : g[u])
        if(!vis[v])
            topo(v);
    
    top.push_back(u);
}

void dfs(int u){
    vis[u] = 1;
    component.push_back(u);

    for(int v : rg[u])
        if(!vis[v])
            dfs(v);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    g.resize(n+1);
    rg.resize(n+1);

    while(m--){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    vis.assign(n+1, 0);
    for(int i=1; i<=n; i++)
        if(!vis[i])
            topo(i);

    reverse(top.begin(), top.end());
    vis.assign(n+1,0);
    ans.assign(n+1,0);
    int tmp = 0;

    for(auto x : top){
        if(!vis[x]){
            component.clear();
            dfs(x);
            tmp++;
            for(int i : component) ans[i] = tmp;
        }
    }

    cout<<tmp<<'\n';
    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
    cout<<'\n';

    return 0;
}