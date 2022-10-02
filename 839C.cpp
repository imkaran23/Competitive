#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;

double dfs(int u, int p){
    double sum = 0, c = 0;
    for(int v : g[u]){
        if(v==p) continue;
        sum += 1 + dfs(v, u);
        c++;
    }
    return sum==0?0:sum/c;
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

        int x, y;
        for(int i=1; i<n; i++){
            cin>>x>>y;
            g[y].push_back(x);
            g[x].push_back(y);
        }

        printf("%.9lf", dfs(1,-1));
    }

    return 0;
}