#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    t = 1;
    // cin>>t;

    while(t--){
        string s;
        cin>>s;
        int n = s.size();

        reverse(s.begin(), s.end());
        map<int, int> mp;

        long long sum = 0, p = 1, ans = 0;

        for(int i=0; i<n; i++){
            int x = s[i]-'0';
            sum = (x*p + sum)%2019;
            p = (p*10)%2019;
            if(sum==0) ans++;
            ans += mp[sum];
            mp[sum]++;
        }

        cout<<ans<<'\n';
    }

    return 0;
}