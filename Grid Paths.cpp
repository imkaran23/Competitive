#include<bits/stdc++.h>
using namespace std;
int dp[1000001];

int solve(int n){
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1) return dp[n];
    
    int d[10];
    for(int i = 0; i < 10; i++) d[i] = 0;
    int z = n;
    while(n>0){
        d[n%10] = 1;
        n /= 10;
    }
    n = z;


    int tmp = INT_MAX;
    
    for(int i=1; i<10; i++){
        if(d[i]==1){
            tmp = min(tmp, 1 + solve(n-i));
        }
    }

    return dp[n] = tmp;
}


int main(){
    int n, m = 1000000007;
    cin>>n;
    char a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    if(a[0][0] == '*'){
        cout<<0;
        return 0;
    }

    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[1][1] =  1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 && j==1)
                continue;

            if(a[i-1][j-1]=='.')
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            
            dp[i][j] %= m;
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

    cout<<dp[n][n];
    return 0;
}