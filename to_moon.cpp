#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
vector<vector<int> > v;
vector<bool> vis(100001,false);
int cnt;

void dfs(int x){
    vis[x]=true;
    cnt++;
    f(i,0,v[x].size()-1){
        if(!vis[v[x][i]])
            dfs(v[x][i]);
    }
}

int main(){
    int n,p,x,y;
    cin>>n>>p;
    v.resize(n);

    f(i,1,p){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> ans;
    f(i,0,n-1){
        cnt=0;
        if(!vis[i]){
            dfs(i);
            ans.push_back(cnt);
        }
    }
    
    long long sumsquare=0, squaresum=0;
    for (int i=0;i<ans.size();i++)
    {
        sumsquare += ans[i];
        squaresum += ans[i] * ans[i];
    }
    sumsquare = sumsquare * sumsquare;
    long long sum = ( sumsquare - squaresum ) / 2;
    cout<<sum<<endl;
    return 0;
}