
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,m,a,b,x,k;

void djikstra(vector<vector<pair<int, ll>>>& g, int source){

    priority_queue<ll> ans[n+1];
    ans[source].push(0);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();

        //Iske bina TLE , intuition ?
        if(d > ans[u].top()) continue;

        for(auto x : g[u]){
            auto v =  x.first;
            auto w = x.second;

            ll tmp = d + w;
            if(ans[v].size()>=k){
                if(tmp < ans[v].top()){
                    ans[v].pop();
                    ans[v].push(tmp);
                    pq.push({tmp, v});
                }
            }
            else{
                ans[v].push(tmp);
                pq.push({tmp, v});
            }
        }
    }

    vector<ll> dist;
    while(k--){
        dist.push_back(ans[n].top());
        ans[n].pop();
    }
    reverse(dist.begin(), dist.end());

    for(auto x : dist) cout<<x<<' ';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;

    vector<vector<pair<int, ll>>> graph(n+1);

    for(int i=0; i<m; i++){
        cin>>a>>b>>x;
        graph[a].push_back({b,x});
    }

    djikstra(graph, 1);

    return 0;
}

