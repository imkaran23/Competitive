<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&g, vector<int>&c, int u, bool& ans){
    for(auto v : g[u]){
        if(c[v]==-1){
            c[v] = 1-c[u];
            dfs(g,c,v,ans);
        }
        else if(c[v]==c[u]){
            ans = false;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> c(n+1, -1);

    while(m--){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool ans = true;

    for(int i=1; i<=n; i++){
        if(c[i]==-1){
            c[i] = 0; 
            dfs(g, c ,i, ans);
        }
    }

    if(ans){
        for(int i=1; i<=n; i++){
            cout<<c[i]+1<<" ";
        }
    }
    else cout<<"IMPOSSIBLE";

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&g, vector<int>&c, int u, bool& ans){
    for(auto v : g[u]){
        if(c[v]==-1){
            c[v] = 1-c[u];
            dfs(g,c,v,ans);
        }
        else if(c[v]==c[u]){
            ans = false;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> c(n+1, -1);

    while(m--){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool ans = true;

    for(int i=1; i<=n; i++){
        if(c[i]==-1){
            c[i] = 0; 
            dfs(g, c ,i, ans);
        }
    }

    if(ans){
        for(int i=1; i<=n; i++){
            cout<<c[i]+1<<" ";
        }
    }
    else cout<<"IMPOSSIBLE";

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}