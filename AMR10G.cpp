#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int n,k; 
        cin >> n >> k; 
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(k==1){ 
            cout<<0<<"\n";
            continue;
        }
        sort(a,a+n);
        int ans = INT_MAX;
        for(int i=0;i+k-1<n;i++){
            ans = min(ans,a[i+k-1]-a[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}