#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        long long int r,b,d;
        cin>>r>>b>>d;

        if(r>b) swap(r,b);

        if(b <= r*(1+d)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}