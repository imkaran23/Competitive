/*
PT07Y - Is it a tree
#dfs

You are given an unweighted, undirected graph. Write a program to check if it's a tree topology.

Input
The first line of the input file contains two integers N and M --- number of nodes and number of edges in the graph (0 < N <= 10000, 0 <= M <= 20000). Next M lines contain M edges of that graph --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).

Output
Print YES if the given graph is a tree, otherwise print NO.

Example
Input:
3 2
1 2
2 3

Output:
YES
*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
vector<vector<int> > v;
vector<bool> vis(10001,false);
int cnt=0;

void dfs(int x){
    vis[x]=true;
    cnt++;
    f(i,0,v[x].size()-1){
        if(!vis[v[x][i]])
            dfs(v[x][i]);
    }
}

int main(){
    int n,m,x,y;
    cin>>n>>m;
    v.resize(n+1);
    f(i,1,m){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    if( n==cnt && m==n-1)
        cout<<"YES\n";
    else 
        cout<<"NO\n";
    return 0;
}