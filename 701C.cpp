#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& mp, vector<int>& nmp){
    int n = mp.size();
    for(int i=0 ; i<n; i++){
        if(mp[i]==0 && nmp[i]==0 || mp[i]>0 && nmp[i]>0) continue;
        else return false;
    }
    return true;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    T = 1;
    // cin>>t;

    while(T--){
        int n;
        string s;
        cin>>n>>s;

        
        vector<int> mp(128, 0), nmp(128,0);
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        int l=0, ans = n+1;

        for(int i=0; i<n; i++){
            nmp[s[i]]++;
            while(check(mp, nmp) && l<n){
                ans = min(ans, i-l+1);
                nmp[s[l]]--;
                l++;
            }
            
        }

        cout<<ans;
    }

    return 0;
}