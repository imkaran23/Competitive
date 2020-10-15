#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159265359;

int check(vector<vector<int>>& a, double x){
    double ans = 0;
    for(int i=0; i<a.size(); i++) if(x>a[i][0]) ans += min(x-a[i][0],(double)a[i][1]) * a[i][2] * a[i][3];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,v;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<int> > a(n,vector<int>(4));
        double lo = 0, hi = 0, mid, total = 0;

        for(int i=0; i<n; i++){ 
            cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
            total += a[i][1]*a[i][2]*a[i][3];
            hi = max(hi, (double)(a[i][0] + a[i][1]));
        }
        
        cin>>v;
        if(total<v) printf("OVERFLOW\n");
        else if(total==v) printf("%.2f\n", hi);
        else{
            int iter = 100;
            while(lo<hi && iter--){
                mid = lo + (hi-lo)/2;
                double ans = check(a,mid);
                if(ans < v) lo = mid + 0.0001;
                else hi = mid - 0.0001;
            } 
            printf("%.2f\n", mid);
        }
    }
    return 0;
}