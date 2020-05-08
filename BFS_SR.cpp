#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)


int main(){
    int t,n,m,x,y,s;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int> > v(n+1);
        vector<bool> vis(n+1,false);
        vector<int> ans(n+1,-1);
        while(m--){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cin>>s;

        queue<int> q;
        q.push(s);
        ans[s]=0;
        vis[s]=true;
        int level=1,k=0;
        while (!q.empty()){
            x=q.front();
            q.pop();
            f(i,0,v[x].size()-1){
                if(!vis[v[x][i]]){
                    ans[v[x][i]]=ans[x]+1;
                    vis[v[x][i]]=true;
                    q.push(v[x][i]);
                }
            }
            level++;
        }

        f(i,1,ans.size()-1){
            if(i==s)
                continue;
            if(ans[i]==-1)
                cout<<-1<<" ";
            else 
                cout<<6*ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}