#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int n; 
        cin >> n; 
        int z = n/2020;
        if(n%2020 <=z ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}