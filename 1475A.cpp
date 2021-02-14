#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int64_t n; 
        cin >> n; 
        while(n>0 && n%2==0){
            n/=2;
        }
        if(n>1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}