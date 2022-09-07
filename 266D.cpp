#include<bits/stdc++.h>
using namespace std;

long long dp[100005][5];

long long recur(vector<pair<int, pair<int, int>>>& v, int i, int t, int x){

    if(i==v.size()) return 0;

    if(dp[t][x]!=-1) return dp[t][x];

    long long tmp = 0;

    if( v[i].first - t >= abs(v[i].second.first - x) )
        tmp = max(tmp, v[i].second.second + recur(v, i+1, v[i].first, v[i].second.first));

    tmp = max(tmp, recur(v, i+1, t, x));

    cout<<i<<' '<<t<<' '<<x<<' '<<tmp<<'\n';

    return dp[t][x] = tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, pair<int, int>>> v(n);

    for(int i=0; i<n; i++){
        int a, b , c;
        cin>>a>>b>>c;
        v[i] = {a,{b,c}};
    }

    memset(dp, -1, sizeof(dp));
    cout<<recur(v, 0, 0, 0);

    return 0;
}