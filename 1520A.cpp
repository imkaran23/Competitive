#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v(26,0);
        bool ans = true;
        v[s[0]-'A']++;
        for(int i=1;i<n; i++){
            if(s[i]!=s[i-1] && v[s[i]-'A']) {
                ans = false;
                break;
            }
            else v[s[i]-'A']++;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}