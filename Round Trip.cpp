<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g, vector<int>& vis, int u, int parent,
           vector<int>& tmp, vector<int>& ans){
    vis[u] = 1;
    tmp.push_back(u);

    for(auto v : g[u]){
        if(vis[v]==0){
            dfs(g, vis, v, u, tmp, ans);
        }
        else if(v!=parent){
            if(ans.size()>0) return;
            int i = 0;
            for(i=0; i<tmp.size(); i++)
                if(tmp[i]==v) break;
            for(int j = i; j<tmp.size(); j++)
                ans.push_back(tmp[j]);
            ans.push_back(ans[0]);
            return;
        }
    }

    tmp.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;

    cin>>n>>m;

    if(n<3){
       cout<<"IMPOSSIBLE";
       return 0; 
    }

    vector<vector<int>> v(n+1);
    vector<int> vis(n+1, 0), ans, tmp;

    while(m--){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(v, vis, i, -1, tmp, ans);
        }
    }

    if(ans.size()>0){
        cout<<ans.size()<<"\n";
        for(auto x : ans) cout<<x<<" ";
    }
    else cout<<"IMPOSSIBLE";

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g, vector<int>& vis, int u, int parent,
           vector<int>& tmp, vector<int>& ans){
    vis[u] = 1;
    tmp.push_back(u);

    for(auto v : g[u]){
        if(vis[v]==0){
            dfs(g, vis, v, u, tmp, ans);
        }
        else if(v!=parent){
            if(ans.size()>0) return;
            int i = 0;
            for(i=0; i<tmp.size(); i++)
                if(tmp[i]==v) break;
            for(int j = i; j<tmp.size(); j++)
                ans.push_back(tmp[j]);
            ans.push_back(ans[0]);
            return;
        }
    }

    tmp.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;

    cin>>n>>m;

    if(n<3){
       cout<<"IMPOSSIBLE";
       return 0; 
    }

    vector<vector<int>> v(n+1);
    vector<int> vis(n+1, 0), ans, tmp;

    while(m--){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(v, vis, i, -1, tmp, ans);
        }
    }

    if(ans.size()>0){
        cout<<ans.size()<<"\n";
        for(auto x : ans) cout<<x<<" ";
    }
    else cout<<"IMPOSSIBLE";

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}