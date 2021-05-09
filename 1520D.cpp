#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        long long int n,x;
        cin>>n;
        unordered_map<int , int> mp;

        for(int i = 0; i<n; i++){
            cin>>x;
            mp[x-i]++;
        }

        long long ans = 0;
        for(auto it : mp){
            x = it.second;
            if(x>0) ans += (x*(x-1))/2;
        }

        cout<<ans<<"\n";
    }
    return 0;
}