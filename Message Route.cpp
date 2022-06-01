#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;

    cin>>n>>m;

    vector<vector<int>> g(n+1);

    while(m--){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n+1, INT_MAX), ans(n+1);
    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto v : g[u]){
            if(dist[v]>dist[u]+1){
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
                ans[v] = u;
            }
        }
    }

    if(dist[n]==INT_MAX)
        cout<<"IMPOSSIBLE\n";
    else{
        cout<<dist[n]+1<<'\n';
        vector<int> v;

        int x = n;
        while(x>0){
            v.push_back(x);
            x = ans[x];
        }

        reverse(v.begin(), v.end());
        for(auto y : v)
            cout<<y<<" ";
    }
    

    return 0;
}