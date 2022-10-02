#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    // T = 1;
    cin>>T;

    while(T--){
        int n, c, x;
        cin>>n>>c;

        map<int, int> mp;
        for(int i=0; i<n; i++){
            cin>>x;
            mp[x]++;
        }

        ll ans = 0;
        for(auto y : mp){
            ans += min(y.second, c);
        }

        cout<<ans<<'\n';
    }

    return 0;
}