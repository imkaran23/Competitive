<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& t, vector<int>& ans, int u){
    int emp = 0;
    for(int v: t[u]){
        emp += dfs(t, ans, v);
    }

    ans[u] = emp;
    return 1+emp;
}

int main(){
    int n, m = 1000000007, x;
    cin>>n;
    vector<vector<int>> v(n+1);

    for(int i=2;i <=n; i++){
        cin>>x;
        v[x].push_back(i);
    }

    vector<int> ans(n+1,0);
    dfs(v, ans, 1);

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& t, vector<int>& ans, int u){
    int emp = 0;
    for(int v: t[u]){
        emp += dfs(t, ans, v);
    }

    ans[u] = emp;
    return 1+emp;
}

int main(){
    int n, m = 1000000007, x;
    cin>>n;
    vector<vector<int>> v(n+1);

    for(int i=2;i <=n; i++){
        cin>>x;
        v[x].push_back(i);
    }

    vector<int> ans(n+1,0);
    dfs(v, ans, 1);

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    
    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}