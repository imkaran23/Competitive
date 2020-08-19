#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    vector<int> dp(n,1);
    for(int i=0; i<n; i++){ 
        cin>>a[i];
        for(int j=0; j <i;j++){
            if(a[i]>0){
                if(a[j]<0 && abs(a[j])<a[i]) dp[i] = max(dp[i],dp[j]+1);
            }
            else{
                if(a[j]>0 && a[j]<abs(a[i])) dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    int ans=1;
	for(int i=0;i<n;i++)
		ans=max(ans,dp[i]);
        
    cout<<ans<<endl;
    return 0;
}