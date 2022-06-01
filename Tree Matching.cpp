#include<bits/stdc++.h>
using namespace std;
int ans;

void dfs(vector<vector<int>>& t, vector<int>& vis,int parent, int u){
    for(int v: t[u]){
        if(v!=parent){
            dfs(t, vis, u, v);
            if(!vis[u] && !vis[v]){
                vis[u]=1;
                vis[v]=1;
                ans++;
            }
        }
    }
}

int main(){
    int n, m = 1000000007, x, y;
    cin>>n;
    vector<vector<int>> v(n+1);

    for(int i=2;i <=n; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> vis(n+1, 0);
    ans = 0;
    dfs(v, vis, 0, 1);

    cout<<ans;
    
    return 0;
}