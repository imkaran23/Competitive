#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        sort(a,a+n);
        int i = n-2;
        long long ans = a[n-1];
        for(int count=1; count<=k; count++){
            ans += a[i];
            i--;
        }
        cout<<ans<<endl;
    }
    return 0;
}