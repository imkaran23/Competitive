#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,a,b;
    cin>>n;

    vector<pair<long long, long long> > v;

    while(n--){
        cin>>a>>b;
        v.push_back({a,b});
    }

    long long ans = 0, tmp = 0;

    sort(v.begin(), v.end());

    for(auto x : v){
        tmp += x.first;
        ans += x.second - tmp;
    }

    cout<<ans;

    return 0;
}