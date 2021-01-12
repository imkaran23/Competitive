#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int a[n], s = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            s+=a[i];
        } 

        if(s==m) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}