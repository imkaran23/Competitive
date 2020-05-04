#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)

int main(){
    string str;
    cin>>str;
    int n = str.size();
    int dp[n][n];

    f(i,0,n) 
      dp[i][i] = 1; 
  
    f(cl,2,n) 
    { 
        f(i,0,n-cl+1) 
        { 
            int j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               dp[i][j] = 2; 
            else if (str[i] == str[j]) 
               dp[i][j] = dp[i+1][j-1] + 2; 
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
        } 
    } 

    cout<<dp[0][n-1]<<endl;
    return 0;
}