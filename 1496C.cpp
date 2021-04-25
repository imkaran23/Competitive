#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n; 
        int x,y;
        vector<int> a,b;
        for(int i=0; i<2*n; i++) {
            cin>>x>>y;
            if(x==0) a.push_back(abs(y));
            else b.push_back(abs(x));
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        double ans=0;
        for(int i=0; i<n; i++) ans += sqrt(a[i]*(double)a[i] + b[i]*(double)b[i]);
        printf("%.15lf\n", ans);
    }
}