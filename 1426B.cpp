#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,a,b,c,d;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool ans = false;
        for(int i=0; i<n; i++){
            cin>>a>>b>>c>>d;
            if(b==c) ans = true;
        }

        if(ans && m%2==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}