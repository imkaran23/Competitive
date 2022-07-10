#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(vector<vector<pair<ll,ll>>>& g, vector<int>& vis, int s){
    if (vis[s]) return;
    vis[s]=1;
    for (auto i: g[s]) dfs(g, vis, i.first);
}

ll BellmanFord(vector<vector<ll>>& graph, vector<vector<pair<ll,ll>>>&g , vector<vector<pair<ll,ll>>>& rg, ll& n, ll& m, ll src){
    vector<int> vis1(n+1,0), vis2(n+1,0);
    dfs(g, vis1, 1);
    dfs(rg, vis2, n);

    vector<ll> dist(n, INT64_MAX);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[graph[j][0]] != INT64_MAX && dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
        }
    }

    // Check for negative-weight cycles. The above step guarantees shortest distances if graph doesn't contain negative weight cycle.
    // If we get a shorter path, then there is a cycle. AND if the cyle is be a part of path between 1 and n , then -1
    // ALGO : 1 to n dfs mark nodes in graph, n to 1 dfs mark nodes in reverse graph, if common during the negative cycle test then return -1.    
    for (int i = 0; i < m; i++) {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dist[x] != INT64_MAX && dist[x] + weight < dist[y] && vis1[y+1] && vis2[y+1]){
            return -1;
            // cout << "Graph contains negative weight cycle"<< endl;
        }
    }

    return -dist[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,a,b,x;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>> g(n+1), rg(n+1);
    vector<vector<ll>> g1; 

    for(int i=0; i<m; i++){
        cin>>a>>b>>x;
        g[a].push_back({b,-x});
        rg[b].push_back({a,-x});
        g1.push_back({a-1,b-1,-x});
    }

    cout << BellmanFord(g1, g, rg, n, m, 0);

    return 0;
}