#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,ans;
    cin>>t;
    while(t--){
        cin>>n;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){ 
            cin>>x;
            mp[x]++;
        }
        
        ans=0;
        for(int w=2; w<=2*n; w++){
            int tmp = 0;
            for(int i=1; i<=w/2; i++){
                if(i == w-i) tmp += mp[i]/2;
                else tmp += min(mp[i],mp[w-i]);
            }
            ans = max(ans,tmp);
        }

        cout<<ans<<endl;
    }
}