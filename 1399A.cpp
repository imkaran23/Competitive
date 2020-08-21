#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,count;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        sort(a,a+n);
        count=0;
        for(int i=0; i<n-1; i++) if(a[i+1]-a[i]<=1) count++;

        if(n-count == 1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}