#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<limits.h>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define SIZE 10000 + 1
vector<vector<pair<int,int> > > v;
map<string,int> mp;
vector<int> dist;
bool vis [SIZE];

void dijkstra(int u){
    dist.assign(SIZE,200000);
    memset(vis,false,sizeof(vis)); 
    dist[u] = 0;
    multiset<pair<int,int> > s;  
    s.insert({0 , u});                  

    while(!s.empty()){
        pair<int,int> p = *s.begin();  
        s.erase(s.begin());
        int x = p.second; int w = p.first;
        if( vis[x] ) 
            continue;                
        vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].first; 
            int w = v[x][i].second;
            if(dist[x] + w < dist[e] ){           
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );          
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,y,cost,p,r;
        cin>>n;
        v.clear();
        v.resize(n+1);
        f(x,1,n){
            string s;
            cin>>s;
            mp[s]=x;
            cin>>p;
            while(p--){
                cin>>y>>cost;
                v[x].push_back(make_pair(y,cost));
            }
        }

        cin>>r;
        while(r--){
            string s1,s2;
            cin>>s1>>s2;
            int u=mp[s1];
            int v=mp[s2];
            dijkstra(u);
            cout<<dist[v]<<endl;
        }
    }
    return 0;
}