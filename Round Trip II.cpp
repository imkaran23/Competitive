#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g, vector<int>& vis, vector<int>& rec, int u,
           vector<int>& tmp, vector<int>& ans){

    vis[u] = 1;
    tmp.push_back(u);
    rec[u] = 1;

    for(auto v : g[u]){
        if(vis[v]==0){
            dfs(g, vis, rec, v, tmp, ans);
        }
        else if(rec[v]){
            if(ans.size()>0) return;
            int i = 0;
            for(i=0; i<tmp.size(); i++)
                if(tmp[i]==v) break;

            unordered_set<int> st;
            vector<int> tmp1;

            for(int j = i; j<tmp.size(); j++){
                tmp1.push_back(tmp[j]);
                st.insert(tmp[j]);
            }

            if(st.size() == tmp1.size()){
                tmp1.push_back(tmp1[0]);
                ans = tmp1;
            }
            return;
        }
    }

    rec[u] = 0;
    tmp.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;

    cin>>n>>m;

    vector<vector<int>> v(n+1);
    vector<int> vis(n+1, 0), rec(n+1,0), ans, tmp;

    while(m--){
        cin>>a>>b;
        v[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(v, vis, rec, i, tmp, ans);
        }
    }

    if(ans.size()>0){
        cout<<ans.size()<<"\n";
        for(auto x : ans) cout<<x<<" ";
    }
    else cout<<"IMPOSSIBLE";

    return 0;
}