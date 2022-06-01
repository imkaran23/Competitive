#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,t;
    cin>>n>>x;

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
        if(mp.find(sum-x)!=mp.end()) 
            ans += mp[sum-x];
        mp[sum]++;
    }

    cout<<ans;

    // long long ans = 0, sum = v[0];
    
    // int l = 0, r = 0;
    // while(r<n){
    //     if(sum==x){
    //         ans++;
    //         r++;
    //         if(r<n) sum += v[r];
    //     }
    //     else if(sum<x){
    //         r++;
    //         if(r<n) sum += v[r];
    //     }
    //     else{
    //         sum-=v[l];
    //         l++;
    //     }
    // }
    // cout<< ans;

    return 0;
}