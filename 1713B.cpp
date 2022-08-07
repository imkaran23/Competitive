#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n];

        for(int i=0; i<n; i++) cin>>a[i];

        int j = 1;
        while(a[j]>=a[j-1] && j<n) j++;
        while(a[j]<=a[j-1] && j<n) j++;

        if(j==n) cout<<"YES\n";
        else cout<<"NO\n";

    return 0;
}