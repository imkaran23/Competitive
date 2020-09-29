#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans = 1e9;
        for (int x = 1; x * x <= n; ++x){
            int y = ceil((float)(n-x)/x);
            ans = min(ans, x-1 + y) ;
        }
            
        cout<<ans<<endl;
    }
    return 0;
}