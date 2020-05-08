/*
PT07Z - Longest path in a tree
#dfs

You are given an unweighted, undirected tree. Write a program to output the length of the longest path (from one node to another) in that tree. The length of a path in this case is number of edges we traverse from source to destination.

Input
The first line of the input file contains one integer N --- number of nodes in the tree (0 < N <= 10000). Next N-1 lines contain N-1 edges of that tree --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u, v <= N).

Output
Print the length of the longest path on one line.

Example
Input:
3
1 2
2 3

Output:
2

#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
vector<vector<int> > v;
vector<bool> vis;
int edge=0,maxi=0,last=-1;

void dfs(int x,int edge){
    vis[x]=true;
    if(edge>maxi){    
        maxi=edge;
        last=x;
    }
    f(i,0,v[x].size()-1){
        if(!vis[v[x][i]]){
            dfs(v[x][i],++edge);
        }
    }
}

int get(int x){
    if(v[x].size()==0)
        return x;
    return get(v[x][0]);
}

int main(){
    int n,x,y;
    cin>>n;
    v.resize(n+1);
    vis.resize(n+1);

    f(i,1,n-1){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    vis.resize(n+1);
    dfs(last,0);
    cout<<maxi<<endl;
    return 0;
}
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int visited[10005];
vector < int > V[10005];
int maxL=0,last=0;
void dfs(int v,int path)
{
    visited[v]=1;
    if(path>maxL)
    {
        maxL=path;
        last=v;
    }
    for(int i=0;i<V[v].size();i++)
        if(!visited[V[v][i]])
            dfs(V[v][i],path+1);
}
int main()
{
    int n;
    cin>>n;
    int i,u,v;
    for(i=0;i<n-1;i++)
    {

        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    dfs(1,0);
    int ans;
    ans=maxL;
    memset(visited,0,sizeof(visited));
    dfs(last,0);
    cout<<maxL<<endl;
return 0;
}