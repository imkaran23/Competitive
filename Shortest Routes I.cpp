<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
#define ii pair<long long, long long>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b,c;

    cin>>n>>m;
    vector<vector<ii>> v(n+1);
    vector<long long> dist(n+1, INT64_MAX), vis(n+1,0);

    while(m--){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        // v[b].push_back({a,c});
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dist[1] = 0;
    pq.push({0,1});

    while (!pq.empty()){
        auto u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(auto x : v[u]){
            auto v = x.first;
            auto w = x.second;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
        
    for(int i=1; i<=n; i++)
        cout<<dist[i]<<" ";
    
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;
#define ii pair<long long, long long>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b,c;

    cin>>n>>m;
    vector<vector<ii>> v(n+1);
    vector<long long> dist(n+1, INT64_MAX), vis(n+1,0);

    while(m--){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        // v[b].push_back({a,c});
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dist[1] = 0;
    pq.push({0,1});

    while (!pq.empty()){
        auto u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(auto x : v[u]){
            auto v = x.first;
            auto w = x.second;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }
        
    for(int i=1; i<=n; i++)
        cout<<dist[i]<<" ";
    
    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}