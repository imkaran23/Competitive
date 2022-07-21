#include<bits/stdc++.h>
using namespace std;

int n, x, y;
vector<long long int> dp(200001, 0), ans(200001, 0); 

int dfs1(vector<vector<int>>& t, int parent, int u, long long int d = 0){

    ans[1] += d;
    dp[u] = 1;
    for(int v: t[u]){

        if(v!=parent){
            dfs1(t, u, v, d+1);
            dp[u] += dp[v];
        }
    }
}

void dfs2(vector<vector<int>>& t, int parent, int u){

    for(int v: t[u]){
        
        if(v!=parent){
            ans[v] = ans[u] - dp[v] + n - dp[v];
            dfs2(t, u, v);
        }
    }
}

int main(){
    cin>>n;
    vector<vector<int>> v(n+1);

    for(int i=1 ;i <n; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs1(v, -1, 1);
    dfs2(v, -1, 1);

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
    
    return 0;
}