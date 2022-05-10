#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& g, vector<int>& vis, int u){
    vis[u] = 1;

    for(auto v : g[u]){
        if(vis[v]==0){
            solve(g, vis, v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;

    cin>>n>>m;

    vector<vector<int>> v(n+1);
    vector<int> vis(n+1, 0), ans;

    while(m--){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int count = 0;

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            solve(v, vis, i);
            ans.push_back(i);
            count++;
        }
    }

    cout<<count-1<<'\n';

    for(int i=0; i<ans.size()-1; i++){
        cout<<ans[i]<<" "<<ans[i+1]<<"\n";
    }

    return 0;
}