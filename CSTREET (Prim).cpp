#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
const int MAX = 1e3 + 1;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        x = p.second;
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int p,n,m,a,b,c;
        cin>>p>>n>>m;
        f(i,1,m){
            cin>>a>>b>>c;
            adj[a].push_back(make_pair(c, b));
            adj[b].push_back(make_pair(c, a));
        }
        cout<<p*prim(1)<<endl;
    }
    return 0;
}
