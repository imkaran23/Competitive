#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
char a[1001][1001];
long long int dp[1001][1001];
int h,w;



int main(){
    cin>>h>>w;
    f(i,1,h){
        f(j,1,w){
            cin>>a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    f(i,1,h){
        f(j,1,w){
            if(a[i][j]=='#')
                continue;
            if(i==1&&j==1)
                dp[i][j]=1;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
        }
    }

    cout<<dp[h][w]<<endl;
    return 0;
}