#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    t = 1;
    // cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        int pre[n], suf[n];
        pre[0] = a[0];
        suf[n-1] = a[n-1];

        for(int i=1; i<n; i++) pre[i] = gcd(pre[i-1], a[i]);
        for(int i= n-2; i>=0; i--)  suf[i] = gcd(suf[i+1], a[i]);     

        int ans = max(suf[1], pre[n-2]);
        for(int i=1; i<n-1; i++) ans = max(ans, gcd(pre[i-1], suf[i+1]));
        cout<<ans<<'\n';
    }

    return 0;
}