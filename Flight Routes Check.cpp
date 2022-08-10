#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lli pair<ll, int>
const ll mod = 1e9+7;

vector<vector<int>> g1, g2;
vector<int> vis;
int n, m;

void dfs(int i, vector<vector<int>>& g){
    vis[i] = 1;

    for(auto x : g[i]){
        if(vis[x] == 0)
            dfs(x, g);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    g1.resize(n+1);
    g2.resize(n+1);

    while(m--){
        int a,b; 
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }

    vis.assign(n+1,0);
    dfs(1, g1);
    // for (int i = 1; i <= n; i++) cout<<vis[i]<<' ';
    // cout<<'\n';
    for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << 1 << " " << i << '\n';
			return 0;
		}
	}

    vis.assign(n+1, 0);
    dfs(1, g2);
    // for (int i = 1; i <= n; i++) cout<<vis[i]<<' ';
    // cout<<'\n';
    for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << i << " " << 1 << '\n';
			return 0;
		}
	}

    cout<<"YES\n";
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define lli pair<ll, int>
// const ll mod = 1e9+7;

// vector<vector<int>> g1, g2;
// vector<int> vis, component;
// stack<int> topo;

// int n, m;

// void dfs1(int i, vector<vector<int>>& g){
//     vis[i] = 1;

//     for(auto x : g[i]){
//         if(!vis[i])
//             dfs1(x, g);
//     }

//     topo.push(i);
// }

// void dfs2(int i, vector<vector<int>>& g){
//     vis[i] = 1;
//     component[i] = 1;

//     for(auto x : g[i]){
//         if(!vis[i])
//             dfs1(x, g);
//     }
// }

// int main(){
//     cin.tie(0)->sync_with_stdio(0);
    
//     cin>>n>>m;
//     g1.resize(n+1);
//     g2.resize(n+1);

//     while(m--){
//         int a,b; 
//         cin >> a >> b;
//         g1[a].push_back(b);
//         g2[b].push_back(a);
//     }

//     vis.assign(n+1,0);
//     for(int i=1; i<=n; i++) 
//         if(vis[i]==0)
//             dfs1(i, g1);

//     vis.assign(n+1, 0);

//     while(!topo.empty()){
//         int i = topo.top();
//         topo.pop();

//         if(vis[i]==0){
//             // component.clear();
//             component.assign(n+1, 0);
//             dfs2(i, g2);

//             int tmp = count(component.begin(), component.end(), 1);
//             if(tmp==n) cout<<"YES\n";
//             else{
//                 cout<<"NO\n";
                
//                 for(int j=1; j<=n; j++){
//                     if(component[j]==1){
//                         cout<<j<<' ';
//                         break;
//                     }
//                 }

//                 for(int j=1; j<=n; j++){
//                     if(component[j]==0){
//                         cout<<j<<' ';
//                         break;
//                     }
//                 } 
//             }
//             return 0;
//         }
//     }

//     return 0;
// }