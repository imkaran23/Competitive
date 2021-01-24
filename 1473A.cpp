#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,d;
    cin>>t;
    while(t--){
        cin >> n >> d;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a,a+n);
        if(a[n-1]<=d || n>2 && a[0]+a[1]<=d) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}
