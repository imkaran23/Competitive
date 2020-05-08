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
    int t,n,m,cl,cr,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>cl>>cr;
        v.clear();
        vis.clear();
        v.resize(n+1);
        f(i,1,m){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        }

        vector<int> ans;
        f(i,1,n){
            cnt=0;
            if(!vis[i]){
                dfs(i);
                ans.push_back(cnt);
            }
        }

        f(i,0,ans.size()-1)
                cout<<ans[i]<<" ";
        cout<<endl;

        long long sum;
        if(cl>cr){
            sum=cl*ans.size();
            f(i,0,ans.size()-1){
                sum+=cr*(ans[i]-1);
            }
        }
        else{
            sum = n*cl;
        }
        cout<<sum<<endl;
    }
    return 0;
}