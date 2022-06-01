<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,m=1000000007;
    cin>>n>>x;

    int a[n], dp[x+1];
    for(int i=0; i<n; i++) cin>>a[i];
    memset(dp,0,sizeof(dp));

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=1; j<=x; j++){
            if(j-a[i]>=0)
                dp[j] += dp[j-a[i]];
                dp[j] %= m;  
        }
    }

    cout<<dp[x];

    return 0; 
=======
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,m=1000000007;
    cin>>n>>x;

    int a[n], dp[x+1];
    for(int i=0; i<n; i++) cin>>a[i];
    memset(dp,0,sizeof(dp));

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=1; j<=x; j++){
            if(j-a[i]>=0)
                dp[j] += dp[j-a[i]];
                dp[j] %= m;  
        }
    }

    cout<<dp[x];

    return 0; 
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}