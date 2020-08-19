#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
const int mod = 1e9+7;
int dp[maxn][maxn];
int main()
{
    int n, k;
    scanf("%d %d",&n, &k);
    for(int i=1; i<=n; i++)
        dp[1][i] = 1;
    for(int i=1; i<k; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dp[i][j])
            {
                for(int l=j; l<=n; l+=j)
                {
                    dp[i+1][l] += dp[i][j];
                    dp[i+1][l] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}