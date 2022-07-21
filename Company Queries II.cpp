#include<bits/stdc++.h>
using namespace std;

int n, x, y, q, k;
vector<vector<int>> go_up(20, vector<int>(200001)), tree(200001);
vector<int> depth(200001);

void dfs(int u, int d){
    depth[u] = d;
    for(int v : tree[u]){
        dfs(v, d+1);
    }
}

int jump(int x, int k){
    for(int i = 0; i<20; i++) 
        if(  k>>i & 1 )
            x = go_up[i][x];
    
    if(x) return x;
    else return -1;
}

int lcb(int x, int y){
    if(depth[x] > depth[y]) swap(x, y);

    y = jump(y , depth[y] - depth[x]);

    if(y == x) return y; // induced by given example

    for(int i = 19; i>=0; i--){
        int x_ = go_up[i][x], y_ = go_up[i][y];
        if(x_ != y_){
            x = x_;
            y = y_;
        } 
    }

    return go_up[0][x]; // or go_up[0][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;

    for(int i=2 ; i <=n; i++){
        cin>>x;
        tree[x].push_back(i);
        go_up[0][i] = x;
    }

    for(int i = 1; i<20; i++){
        for(int j = 1; j<=n; j++){
            go_up[i][j] = go_up[i-1][go_up[i-1][j]];
        }
    }

    dfs(1, 0);

    while(q--){
        cin>>x>>y;
        cout<< lcb(x,y) << '\n';
    }
    
    return 0;
}