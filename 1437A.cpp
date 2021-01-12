#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,l,r;
    cin>>t;
    while(t--){
        cin>>l>>r;
        if(r/l==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}