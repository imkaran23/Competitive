#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4+1;
int id[MAX], nodes, edges;
pair<long long,pair<int, int> > p[MAX];
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)

int root(int x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y){
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[]){
    f(i,0,MAX)
        id[i] = i;
    int x, y;
    long long cost, minimumCost = 0;
    f(i,0,edges){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y)){
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main(){
    int x, y;
    long long weight, cost, minimumCost;
    cin>>nodes>>edges;
    f(i,0,edges){
        cin>>x>>y>>weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p,p+edges);
    cout <<kruskal(p)<<endl;
    return 0;
}

/*
#include<bits/stdc++.h> 
using namespace std; 
typedef pair<int, int> iPair; 

struct Graph 
{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 
    Graph(int V, int E) 
    { 
        this->V = V; 
        this->E = E; 
    } 
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
    int kruskalMST(); 
}; 

struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 

    int find(int u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 

    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 

        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 

int Graph::kruskalMST() 
{ 
    int mst_wt = 0;
    sort(edges.begin(), edges.end()); 
    DisjointSets ds(V); 
    for (auto it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 

        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
        if (set_u != set_v) 
        { 
            mst_wt += it->first; 
            ds.merge(set_u, set_v); 
        } 
    } 
    return mst_wt; 
} 

int main() 
{ 
    int V,E; 
    cin>>V>>E;
    Graph g(V, E); 
    for(int i=0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x,y,w);
    }
    int mst_wt = g.kruskalMST(); 
    cout << mst_wt <<endl; 

    return 0; 
} 
*/