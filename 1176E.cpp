#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;
vector<int> c;

// void colorDFS(int u, int p){
//     for(int v : g[u]){
//         if(v==p) continue;
//         if(c[v]==-1){
//             c[v] = 1-c[u];
//             cout<<"Color of "<<v<<' '<<c[v]<<'\n';
//             colorDFS(v, u);
//         }
//     }
// }

void colorBFS(int u){
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int v : g[x]){
            if(c[v]==-1){ 
                c[v] = 1-c[x];
                // cout<<"Color of "<<v<<' '<<c[v]<<'\n';
                q.push(v);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;

    while(t--){

        int n, m;
        cin>>n>>m;

        g.clear();
        g.resize(n+1);
        c.assign(n+1, -1);

        int x, y;
        for(int i=0; i<m; i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        c[1] = 0;
        // colorDFS(1, -1); // isse galat ans as expected
        colorBFS(1);

        ll a = 0;
        for(int i=1; i<=n; i++) 
            if(c[i]==0) a++; 

        if(a<=n/2){
            cout<<a<<'\n';
            for(int i=1; i<=n; i++) 
            if(c[i]==0) cout<<i<<' '; 

        }
        else{
            cout<<n-a<<'\n';
            for(int i=1; i<=n; i++) 
            if(c[i]==1) cout<<i<<' '; 

        }
        cout<<'\n';
    }

    return 0;
}