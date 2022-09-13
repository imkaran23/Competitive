#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    t = 1;
    // cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<string> v(n);
        for(int i=0; i<n ;i++) cin>>v[i];

        auto cmp = [](string& s1, string& s2) { return s1+s2<s2+s1; };

        sort(v.begin(), v.end(), cmp);

        string ans = "";
        for(auto s : v){
            ans += s;
        }

        cout<<ans;
    }

    return 0;
}