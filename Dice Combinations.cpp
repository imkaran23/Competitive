#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m=1000000007;
    cin>>n;

    int dp[n+1];
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        i>6? dp[i] = 0 : dp[i] = 1;
        for(int j = 1; j<=6; j++){
            if(i-j>0){
                dp[i] += dp[i-j]; 
                dp[i] %= m;
            }
        }
    }
    cout<<dp[n];

    return 0; 
}