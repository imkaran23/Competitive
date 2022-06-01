#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>x>>n;

    vector<int> coins(x), dp(n+1, n+1);

    for(int i=0; i<x; i++) cin>>coins[i];

    dp[0] = 0;
    for(int i=0; i<=n; i++)
        for(int c : coins)
            if (i-c>=0) 
                dp[i] = min(dp[i], dp[i-c]+1);
    
    cout<<(dp[n]>n?-1:dp[n]);

    return 0; 
}