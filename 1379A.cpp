#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        unordered_map<char, int> mp;

        for(int i =0; i<n; i++){
            cin>>s;
            for(char c: s) mp[c]++;
        }

        bool ans = true;
        for(auto i = mp.begin(); i!=mp.end(); i++){
            if( (i->second) % n != 0){
                ans = false;
                break;
            }
        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}