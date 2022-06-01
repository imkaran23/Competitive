#include<bits/stdc++.h>
using namespace std;
int dp[501][501];

int solve(int a, int b){
    if(a==b)
        return 0;
    
    if(a>b)
        swap(a,b);
    
    if(dp[a][b]!=-1)
        return dp[a][b];
    
    int tmp = 1 + solve(a, b-a);

    for(int i=1; i<a; i++)
        tmp = min(tmp, 1 + solve(i,b) + solve(a-i,b));
    
    for(int i=1; i<b; i++)
        tmp = min(tmp, 1 + solve(a,i) + solve(a,b-i));

    return dp[a][b] = tmp; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;;
    cin>>a>>b;

    memset(dp, -1, sizeof(dp));
    cout<< solve(a,b);
    return 0;
}