#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back

bool vis[100001];
lli child[100001];
lli cnt[100001];
bool flag[100001];
vector<lli> v[100001];

lli dfs(lli node)
{
    vis[node]=true;
    for(lli chil:v[node]){
        if(!vis[chil]){
            dfs(chil);
        }

        flag[node]|=flag[chil]; // OP logic, keep this approach in mind

        if((cnt[node]<cnt[chil]+1)&&(flag[chil]==true)){
            cnt[node]=cnt[chil]+1;
            child[node]=chil;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli T;
    T=1;

    while(T--){
        lli n,m,i;
        cin>>n>>m;
        lli x,y;
        for(i=0;i<m;i++){
            cin>>x>>y;
            v[x].pb(y);
        }

        flag[n]=true;
        x=dfs(1);

        /*for(i=1;i<=n;i++)
            cout<<child[i]<<" ";*/

        if(!flag[1]) {
            cout<<"IMPOSSIBLE\n";
            continue;
        }

        cout<<cnt[1]+1<<"\n";
        cout<<"1 ";
        lli z=1;

        while(child[z]!=n){
            cout<<child[z]<<" ";
            z=child[z];
        }
        cout<<n;
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define lli pair<ll, int>
// const ll mod = 1e9+7;
 
// vector<vector<int>> g;
// vector<int> vis, par, dp; // dp[i] means max length path from 1 to i
// stack<int> st;
// int n, m;

// void topo(int u){
//     if(vis[u]) return;
//     vis[u] = 1;

//     for(int v : g[u]) topo(v);

//     st.push(u);
// }

// void dfs(int u){
//     if(vis[u]) return ;
//     vis[u] = 1;

//     for(auto v : g[u]){
//         if(vis[v]){
//             if(dp[v] < dp[u] + 1){
//                 par[v] = u;
//                 dp[v] = dp[u] + 1;
//             }
//         }
//         else{
//             par[v] = u;
//             dp[v] = dp[u] + 1;
//             dfs(v);
//         }
//     }
// }

// int main(){
//     cin.tie(0)->sync_with_stdio(0);
    
//     cin>>n>>m;
//     g.resize(n+1);
 
//     while(m--){
//         int a,b,c; 
//         cin >> a >> b;
//         g[a].push_back(b);
//     }
 
//     vis.assign(n+1,0);
//     for(int i=1; i<=n; i++)
//         if(!vis[i])
//             topo(i);

//     vis.assign(n+1,0);
//     dp.assign(n+1, 0);
//     par.assign(n+1, -1);

//     while(!st.empty()){
//         int u = st.top();
//         st.pop();
//         if(!vis[u])
//             dfs(u);
//     }

//     vector<int> ans;
//     int x = n;
//     while(x!=-1){
//         ans.push_back(x);
//         x = par[x];
//     }
//     reverse(ans.begin(), ans.end());

//     if(ans[0]!=1) cout<<"IMPOSSIBLE\n";
//     else{
//         cout<<ans.size()<<'\n';
//         for(int x : ans) cout<<x<<' ';
//     }

//     return 0;
// }
