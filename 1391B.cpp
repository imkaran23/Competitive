#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        char a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>a[i][j];
        }

        int ans = 0;
        for(int i=0;i<n-1;i++) if(a[i][m-1]!='D') ans++;
        for(int j=0;j<m-1;j++) if(a[n-1][j]!='R') ans++;
        cout<<ans<<endl;
    }
    return 0;
}