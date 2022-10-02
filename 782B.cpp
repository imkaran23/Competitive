#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<int>& x, vector<int>& v, double& mid){
    double maxl = 0, minr = 1e18;

    for(int i=0; i<x.size(); i++){
        maxl = max(maxl, x[i]-v[i]*mid);
        minr = min(minr, x[i]+v[i]*mid);
    }

    if(maxl<=minr) return true;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    T = 1;
    // cin>>t;

    while(T--){
        int n;
        cin>>n;

        vector<int> x(n),v(n);
        int maxi = 0, idx;

        for(int i=0; i<n; i++){
            cin>>x[i];
            if(x[i]>maxi){
                maxi = x[i];
                idx = i;
            }
        }

        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        double l = 0, h = 1e18, ans = -1;
        int itr = 100; 
        while(l<h && itr--){
            double mid = (h+l)/2;

            if(check(x, v, mid)){
                ans = mid;
                h = mid;
            }
            else{
                l = mid;
            }
        }
        
        printf("%.9lf", ans);
    }

    return 0;
}