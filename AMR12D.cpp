#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    string s,rev;
    while (t--) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        cin >> s; 
        rev = s;
        reverse(s.begin(), s.end());
        cout << (s == rev ? "YES\n" : "NO\n") ;
    }
    return 0;
}