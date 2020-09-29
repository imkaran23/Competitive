#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x, ans = 0;
    cin>>n;
    long long sum = 0;
    unordered_map<long long, bool> mp;

    for(int i=0; i<n; i++) {
        cin>>x;
        sum += x;
        if( sum==0 || mp[sum]) {
            ans++;
            mp.clear();
            sum = x;
        }
        mp[sum] = true;
    }
    cout<<ans<<endl;
    return 0;
}