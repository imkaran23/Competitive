#include<bits/stdc++.h>
using namespace std;
int ans;

int dfs(vector<vector<int>>& t,int parent, int u){
    int f = 0, s = 0;
    for(int v: t[u]){
        if(v!=parent){
            int tmp = dfs(t, u, v);
            
            if(tmp>f){
                s = f;
                f = tmp;
            }
            else if(tmp>s){
                s = tmp;
            }

            // cout<<u<<"->"<<v<<":"<<tmp<<"-"<<f<<" "<<s<<"||";
        }
    }

    ans = max(ans, 1+s+f);
    return 1+f;
}

int main(){
    int n, x, y;
    cin>>n;
    vector<vector<int>> v(n+1);

    for(int i=2;i <=n; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    ans = 0;
    dfs(v, 0, 1);

    cout<<ans-1;
    
    return 0;
}