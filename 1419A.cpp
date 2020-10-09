#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        bool odd = false, even = false;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                odd |= ((s[i - 1] - '0') % 2 == 1);
            } else {
                even |= ((s[i - 1] - '0') % 2 == 0);
            }
        } 
        if (n % 2 == 1) {
            cout << (odd ? 1 : 2) << '\n';
        } else {
            cout << (even ? 2 : 1) << '\n';
        }
    }
    return 0;
}