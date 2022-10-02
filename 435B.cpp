#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;
vector<int>  c;

void color(int u, int p){
    for(int v : g[u]){
        if(v==p) continue;
        if(c[v]==-1){
            c[v] = 1-c[u];
            color(v, u);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;

    g.resize(n+1);
    c.resize(n+1, -1);

    int x, y;
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    c[1] = 0;
    color(1, -1);

    ll a = 0, b = 0;
    for(int i=1; i<=n; i++) 
        if(c[i]==0) a++; 
        else b++;

    cout<<a*b-n+1<<'\n';

    return 0;
}