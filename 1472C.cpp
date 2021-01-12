#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n,0);
        int ans = INT_MIN; 
        for(int i=0; i<n; i++){ 
            cin>>a[i];
        }
        
        
        for(int i=n-2; i>=0; i--){
            if(i + a[i] < n) 
                a[i] += a[i + a[i]];
        }

        for(int i=0; i<n; i++) ans = max(ans,a[i]);
        cout<<ans<<"\n";
    }
    return 0;
    
}
