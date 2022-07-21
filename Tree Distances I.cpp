#include<bits/stdc++.h>
using namespace std;

vector<int> f(200001, 0), s(200001, 0), c(200001, 0); //first max, second max, child

void dfs1(vector<vector<int>>& t, int parent, int u){

    for(int v: t[u]){

        if(v!=parent){
            dfs1(t, u, v);
            
            if(f[v] + 1 > f[u]){
                s[u] = f[u];
                f[u] = f[v] + 1;
                c[u] = v;
            }
            else if(f[v] + 1 > s[u]){
                s[u] = f[v] + 1;
            }
        }
    }
}

void dfs2(vector<vector<int>>& t, int parent, int u){

    for(int v: t[u]){
        
        if(v!=parent){

            if(c[u] == v){
                if(s[u] + 1 > f[v]){
                    s[v] = f[v];
                    f[v] = s[u] + 1;
                    c[v] = u;
                }
                else{
                    s[v] = max(s[v], s[u]+1);
                }
            }
            else{
                s[v] = f[v];
                f[v] = f[u] + 1;
                c[v] = u;
            }

            dfs2(t, u, v);
        }
    }
}

int main(){
    int n, x, y;
    cin>>n;
    vector<vector<int>> v(n+1);

    for(int i=1 ;i <n; i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs1(v, -1, 1);
    dfs2(v, -1, 1);

    for(int i=1; i<=n; i++) cout<<f[i]<<' ';
    
    return 0;
}