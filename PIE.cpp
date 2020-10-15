#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265359;

int check(vector<double>& a,double x){
    int ans = 0;
    for(int i=0; i<a.size(); i++) ans += a[i]/x;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,f,r;
    cin>>t;
    while(t--){
        cin>>n>>f;
        vector<double> a(n);
        for(int i=0; i<n; i++){
            cin>>r;
            a[i] = pi * r * r;
        }
        sort(a.begin(), a.end());

        double lo = 0, hi = a[n-1], mid;
        int iter = 100;
        while(lo<hi && iter--){
            mid = lo + (hi-lo)/2;
            int ans = check(a,mid);
            if(ans < f+1) hi = mid-0.00001;
            else lo = mid;
        }

        printf("%.4f\n", mid);
    }
    return 0;
}