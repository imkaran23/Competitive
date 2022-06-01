#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define pb push_back

using namespace std;

int md = 1000000007;

void solve(int n){
    if(n%4==1 || n%4==2){
        cout<<0;
        return;
    }
    int s = (n+1)*n/4;

    int dp[s+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;

    vector<int> v;
    rep(i,1,n) v.pb(i);
    rep(i,0,n-1){
        rev(j,s,0){
            if (j-v[i]>=0) (dp[j]+=dp[j-v[i]])%=md;
        }
    }
    cout<<(dp[s]);  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    solve(n);

    return 0;
}