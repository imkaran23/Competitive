#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cxy, cx, cy, n, x, a, y, b, k;

bool check(vector<ll>& v, ll& mid, ll& k){
    ll ans = 0;
    cxy = cx = cy = 0;

    for(int i=1; i<=min(n,mid); i++){
        if(i%a==0 && i%b==0) cxy++;
        else if(i%a==0) cx++;
        else if(i%b==0) cy++;
    }

    int i=0;
    while(cxy--) ans += (v[i++]/100)*(x+y);
    while(cx--) ans += (v[i++]/100)*x; 
    while(cy--) ans += (v[i++]/100)*y;   

    if(ans>=k) return true;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    // T = 1;
    cin>>T;

    while(T--){
        cin>>n;

        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        cin>>x>>a>>y>>b>>k;

        if(y>x) {
            swap(x,y);
            swap(a,b);
        }

        sort(v.begin(), v.end(), greater<int>());
        int l = 1, h = n, ans = -1;

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