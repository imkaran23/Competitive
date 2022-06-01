#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,t;
    cin>>n;

    vector<long long int> v;

    for(int i=0 ;i<n; i++){
        cin>>t;
        v.push_back(t);
    }

    long long int ans = 0, sum = 0;
    map<long long int , long long int> mp;
    mp[0] = 1;

    for(auto i: v){
        sum += i;
        sum = (sum%n + n)%n;
        if(mp.find(sum)!=mp.end()) 
            ans += mp[sum];
        mp[sum]++;
    }

    cout<<ans;

    return 0;
}