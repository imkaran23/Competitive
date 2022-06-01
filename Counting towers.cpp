<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

long long int dp[1000001][2];

int main(){
    int t,n,m=1000000007;

    cin>>t;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<=1000000; i++){
        dp[i][0] = (dp[i - 1][1] + (4 * dp[i - 1][0]) % m) % m; 
        dp[i][1] = (dp[i - 1][0] + (2 * dp[i - 1][1]) % m) % m;
    }

    while(t--){
        cin>>n;
        cout<< (dp[n][0] + dp[n][1]) % m<<"\n";        
    }

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

long long int dp[1000001][2];

int main(){
    int t,n,m=1000000007;

    cin>>t;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2; i<=1000000; i++){
        dp[i][0] = (dp[i - 1][1] + (4 * dp[i - 1][0]) % m) % m; 
        dp[i][1] = (dp[i - 1][0] + (2 * dp[i - 1][1]) % m) % m;
    }

    while(t--){
        cin>>n;
        cout<< (dp[n][0] + dp[n][1]) % m<<"\n";        
    }

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}