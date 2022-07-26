#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[1 << 10][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);

    while(1){
        int n, m;
        n = 3;
        cin >> m;

        if(m==-1) break;

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) {

            for (int mask = 0; mask < (1 << n); mask++) {

                dp[mask][1] = dp[mask ^ (1 << i)][0]; // Vertical/no tile
                
                if (i && !(mask & (1 << i)) && !(mask & (1 << i - 1))) // Horizontal tile
                    dp[mask][1] += dp[mask ^ (1 << i - 1)][0];

                if (dp[mask][1] >= MOD) dp[mask][1] -= MOD;
            }
            for (int mask = 0; mask < (1 << n); mask++) dp[mask][0] = dp[mask][1];
        }
        cout << dp[0][0]<<'\n';
    }

	return 0;
}