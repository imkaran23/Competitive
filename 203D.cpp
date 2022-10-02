#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool check(vector<vector<ll>> v, ll mid, ll k){

    // cout<<mid<<' ';
    int n = v.size();
    vector<vector<ll>> tmp(n, vector<ll>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = v[i][j]>mid?1:0;
            // cout<<tmp[i][j]<<' ';
        }
        // cout<<'\n';
    }

    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            tmp[i][j] += tmp[i][j-1];
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] += tmp[i-1][j];
        }
    }

    ll limit = k*k/2 + 1;

    for(int i=k-1; i<n; i++){
        for(int j=k-1; j<n; j++){
            int x1 = tmp[i][j];
            int x2 = j-k>=0?tmp[i][j-k]:0;
            int x3 = i-k>=0?tmp[i-k][j]:0;
            int x4 = (i-k>=0&&j-k>=0)?tmp[i-k][j-k]:0;

            int x = x1-x2-x3+x4;

            if(x<limit) return true;
        }
    }

    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    T = 1;
    // cin>>T;

    while(T--){
        ll n, k;
        cin>>n>>k;

        vector<vector<ll>> v(n, vector<ll>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>v[i][j];
            }
        }

        ll l = 0, h = 1e9, ans = -1;

        while(l<=h){
            ll mid = (l+h)/2;
            if(check(v, mid, k)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        cout<<ans<<'\n';
    }

    return 0;
}