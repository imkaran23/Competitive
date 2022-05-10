#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& v, long long mid, long long& t){
    unsigned long long ans = 0;
    for(auto x : v) ans += mid/x;
    return (ans>=t?1:0); 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,t,x;
    cin>>n>>t;

    vector<long long> v;

    while(n--){
        cin>>x;
        v.push_back(x);
    }

    long long l = 1, h = 1e18;
    long long ans = h, mid;

    while(l<=h){
        mid = (l+h)/2;
        // cout<<mid<<'\n';
        if(check(v, mid, t)){
            ans = mid;
            h = mid-1;
        } 
        else l = mid+1;
    }

    cout<<ans;

    return 0;
}