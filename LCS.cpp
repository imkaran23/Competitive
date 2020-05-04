#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)

int main(){
    string s1,s2,ans="";
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    f(i,1,n){
        f(j,1,m){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
        }
    }
    // int i=n,j=m;

    while(n>0 && m>0){
        if(s1[n-1]==s2[m-1]){
            ans = s1[n-1] + ans;
            n--;
            m--;
        }
        else if(dp[n-1][m]>dp[n][m-1])
            n--;
        else
            m--; 
    }

    cout<<ans<<endl;

    return 0;
}