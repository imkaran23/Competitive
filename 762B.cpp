#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    t = 1;
    // cin>>t;

    while(t--){
        int a, b, c;
        cin>>a>>b>>c;

        int n;
        cin>>n;

        vector<pair<int, int>> v;

        for(int i=0; i<n; i++){
            int x;
            string s;
            cin>>x>>s;

            if(s=="USB") v.push_back({x, 0});
            else v.push_back({x, 1});
        }
        
        sort(v.begin(), v.end());

        long long comp = 0, ans = 0;

        for(auto x : v){
            int price = x.first;
            int type = x.second;

            if(type==0){
                if(a) a--, ans += price, comp++;
                else if(c) c--, ans += price, comp++;
            }
            else{
                if(b) b--, ans += price, comp++;
                else if(c) c--, ans += price, comp++;
            }
        }

        cout<<comp<<' '<<ans<<'\n';
    }

    return 0;
}