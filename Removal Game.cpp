#include<bits/stdc++.h>
using namespace std;

long long dp[5001][5001][2];

long long recur(vector<long long>& v, int i, int j, bool b){
    if(i>j) return 0;

    if(dp[i][j][b]!=-1) return dp[i][j][b];

    if(b) return dp[i][j][b] = max( v[i] + recur(v, i+1, j, !b) , v[j] + recur(v, i, j-1, !b));
    else return dp[i][j][b] = min(recur(v, i+1, j, !b) , recur(v, i, j-1, !b));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,x,t,z;
    cin>>n;

    vector<long long> v;

    for(int i=0 ;i<n; i++){
        cin>>t;
        v.push_back(t);
    }

    memset(dp, -1, sizeof(dp));

    cout<<max(recur(v,0,n-1,true), recur(v,0,n-1,false));

    return 0;
}