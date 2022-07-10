#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,m,a,b,x,last_node_updated;

struct edge{
    ll from, to, w;
};

void bellmanFord(vector<edge>& g, int source){
    vector<ll> dist(n+1 , 1e18), parent(n+1,0);
    dist[source] = 0;

    for(int i = 0; i<n; i++){
        last_node_updated = 0;

        for(auto e : g){
            ll u = e.from;
            ll v = e.to;
            ll w = e.w;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                last_node_updated = v;
            }
        }
    }

    if(last_node_updated){
        cout<<"YES\n";
        vector<int> cycle;

        //YES 1 2 4 1 , expected ANS
        //YES 3 4 2 1 2 4 1, OUTPUT of below for loop
		for(int i=0; i<n-1; i++) {
            // cout<<last_node_updated<<' ';
			last_node_updated=parent[last_node_updated];
		}
        //The above step is necessary , it ensures that the last_node_updated belongs to the cycle as there can only be n nodes in cycle. 

		for(int x=last_node_updated; ; x=parent[x]) {
			cycle.push_back(x);
			if (x==last_node_updated && cycle.size()>1) break;
		}
		reverse(cycle.begin(), cycle.end());
		for(int x : cycle) cout << x << ' ';
		cout << '\n';
    }

    else cout<<"NO\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    vector<edge> graph;

    for(int i=0; i<m; i++){
        cin>>a>>b>>x;
        graph.push_back({a,b,x});
    }

    bellmanFord(graph, 1);

    return 0;
}

