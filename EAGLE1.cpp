/*
EAGLE1 - Eagle and Dogs
#graph

Eagle (AKA Mohamed Ahmed) lives in a city consists of n intersections connected by n-1 roads, in a way that can go from any intersection to any other intersection moving along some of these roads.

Every day he starts walking in the city following a simple strategy; if he's at some intersection he has to pick one of the roads connected to it at random such that he hasn't walked through it before and walk through it and and if there isn't any, he stops and goes home.

His only problem is that he's afraid of dogs. He doesn't even like seeing dogs. So he's wondering in the worst scenario, how many dogs he'll have to see during his walk until he stops if he starts walking at some intersection. Can you help him?

Input
The input starts with an integer T (1 <= T <= 10), the number of test cases. following T blocks describing each test case.

Each block starts with a line containing an integer n (2 <= n <= 105), the number of intersections in the city. Intersections are numbers 1 through n.

Followed by n-1 lines each containing integers u, v, (1 <= u, v <= n) and d (1 <= d <= 109), the numbers of intersections at the end of this road and the number od dogs Eagle will see walking in this road.

Output
For each test case print a line containing n integers, the ith integer represents the maximum number of dogs Eagle might see if he starts his walk at intersection i.

Example
Input:
1
4
1 2 3
3 2 4
3 4 5
Output:
12 9 7 12
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int visited[100005];
vector < vector<pair<int,int> > > V;
int maxL;
void dfs(int v,int path)
{
    visited[v]=1;
    if(path>maxL)
    {
        maxL=path;
    }
    for(int i=0;i<V[v].size();i++)
        if(!visited[V[v][i].first])
            dfs(V[v][i].first,path+V[v][i].second);
}
int main()
{
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        int u,v,w;
        V.clear();
        V.resize(n+1);
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            V[u].push_back(make_pair(v,w));
            V[v].push_back(make_pair(u,w));
        }
        
        for(int i=1;i<=n;i++){
            maxL=0;
            memset(visited,0,sizeof(visited));
            dfs(i,0);
            cout<<maxL<<" ";
        }
        cout<<endl;
    }
    return 0;
}