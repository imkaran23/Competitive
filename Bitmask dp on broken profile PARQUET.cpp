// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9 + 7;

// int dp[1 << 10][2];

// int main() {
// 	cin.tie(0)->sync_with_stdio(0);

// 	int n, m;
// 	cin >> n >> m;

// 	dp[0][0] = 1;

// 	for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) {

// 		for (int mask = 0; mask < (1 << n); mask++) {

// 			dp[mask][1] = dp[mask ^ (1 << i)][0]; // Vertical/no tile
            
// 			if (i && !(mask & (1 << i)) && !(mask & (1 << i - 1))) // Horizontal tile
// 				dp[mask][1] += dp[mask ^ (1 << i - 1)][0];

// 			if (dp[mask][1] >= MOD) dp[mask][1] -= MOD;
// 		}
// 		for (int mask = 0; mask < (1 << n); mask++) dp[mask][0] = dp[mask][1];
// 	}
// 	cout << dp[0][0];
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define forw(i,a,b) for(int i=a; i<b; i++) 


vector<vector<ll>> dp;
int n,m;

void calc( int i = 0, int j = 0, int mask = 0, int next_mask = 0){
    
    if(i==n) return;

    if( j>=m ) dp[i+1][next_mask] += dp[i][mask];
    else{
        int my_mask = 1<<j;
        if (mask & my_mask) calc(i, j+1, mask, next_mask); // current cell and cell above it both are empty ?
        else{
            calc(i, j+1, mask, next_mask | my_mask); // fill the domino vertically ?

            if(j+1<m && !(mask & my_mask) && (mask & my_mask) )
                calc(i, j+2, mask, next_mask); // fill the domino horizontally ?
        }
    }  
}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dp.resize(n+1, vector<ll>(1<<m));

    dp[0][0] = 1;

    forw(x,0,n){
        forw(mask,0,1<<m){
            calc(x,0,mask,0);
        }
    }

    forw(i,0,n+1) {forw (j,0,1<<m) cout<<dp[i][j]<<' '; cout<<'\n';}

    cout<<dp[n][0];
    return 0;
}