#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        int i=0, j=n-1, ans = 0;
        while(i<n && a[i]==0) i++;
        while(j>=0 && a[j]==0) j--;

        for(int k=i+1; k<j; k++) if(a[k]==0) ans++;

        cout<<ans<<"\n";
    }
    return 0;
}