#include <bits/stdc++.h>

using namespace std;

int c[52];
int n,m;
long long dp[52][252];
bool calculated[52][252];
long long solve(int i, int total)
{
    if(total<0 || i > m) return 0;
    if(total==0)return 1;
    if(calculated[i][total] == false){ //eliminating overlap
        dp[i][total] = solve(i, total - c[i]) + solve(i+1, total);
        calculated[i][total] = true;
    }
    return dp[i][total];
}
int main(){

    int n;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    cout<<solve(1, n)<<endl;
    return 0;
}