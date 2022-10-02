#include <bits/stdc++.h>
using namespace std;
#define ll long long

double ans;

bool check(vector<ll>& x, vector<ll>& t, double& mid){
    double maxl = 0, minr = INT_MAX;

    for(int i=0; i<t.size(); i++){
        double tmp = mid-t[i];
        maxl = max(maxl, x[i]-tmp);
        minr = min(minr, x[i]+tmp);
    }

    if(maxl<=minr) {
        ans = maxl;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    // T = 1;
    cin>>T;

    while(T--){
        int n;
        cin>>n;

        vector<ll> x(n),t(n);

        for(int i=0; i<n; i++){
            cin>>x[i];
        }

        ll maxt = 0;
        for(int i=0; i<n; i++){
            cin>>t[i];
            maxt = max(maxt, t[i]);
        }

        double l = maxt, h = 1e9;
        int itr = 100; 
        while(itr--){
            double mid = (l+h)/2;
            // cout<<mid<<' ';
            if(check(x, t, mid)){
                h = mid;
            }
            else{
                l = mid;
            }
        }
        
        printf("%.9lf\n", ans);
    }

    return 0;
}