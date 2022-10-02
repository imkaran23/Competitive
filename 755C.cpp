#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;
vector<int> vis;

void dfs(int u){
    vis[u] = 1;
    for(int v : g[u]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    // cin>>t;

    while(t--){

        int n;
        cin>>n;

        g.clear();
        g.resize(n+1);
        vis.assign(n+1, 0);

        int x;
        for(int i=1; i<=n; i++){
            cin>>x;
            g[i].push_back(x);
            g[x].push_back(i);
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                dfs(i);
                ans++;
            }
        }

        cout<<ans;
    }

    return 0;
}