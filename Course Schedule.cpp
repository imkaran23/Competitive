#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> ans;
    
bool iscycle(vector<int> adj[],vector<int> &vis,int id){
    if(vis[id]==1)
        return true;
    if(vis[id]==0){
        vis[id]=1;
        for(auto edge : adj[id]){
            if(iscycle(adj,vis,edge))
                return true;
        }
        ans.push_back(id); 
    }
    
    vis[id] = 2;
    return false;
}
    
vector<int> findOrder(int n, vector<vector<int>>& pre) {
    vector<int> adj[n] , indegrees(n,0);
    for(auto edge : pre){
        adj[edge[1]].push_back(edge[0]);
        ++indegrees[edge[0]];
    }
    
    vector<int> vis(n,0);
    
    for(int i=0;i<n;i++){
        if(vis[i]==0 && iscycle(adj,vis,i))
            return {};
    }
    
    for(int i=0;i<n;i++){
        vis[i] = 0;
    }
    
    ans.clear();
    for(int i=0;i<n;i++){
        if(vis[i]==0 && indegrees[i]==0){
            iscycle(adj, vis, i);
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;
    cin>>n>>m;

    vector<vector<int>> v;
    for(int i=0 ; i<m; i++){
        cin>>a>>b;
        v.push_back({b-1,a-1});
    }
    
    auto ans = findOrder(n, v);

    if(ans.size()) for(auto x : ans) cout<<x+1<<' ';
    else cout<<"IMPOSSIBLE";

    return 0;
}