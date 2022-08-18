#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n], maxi = 0, mini = 0;

        for(int i=0; i<n; i++){ 
            cin>>a[i];
            if(i==0) continue;
            if(a[maxi]<a[i]) maxi = i;
            if(a[mini]>a[i]) mini = i;
        }

        int ans = a[maxi] - a[mini];

        if(mini>maxi) swap(maxi, mini);

        int c1 = mini-1, c2 = maxi + 1;
        int d1 = mini + 1, d2 = maxi - 1;
        int ans1 = 0, ans2 = 0;
        int maxic = INT_MIN, minic = INT_MAX;
        int maxid = INT_MIN, minid = INT_MAX;


        for(int i=0; i<=c1; i++){
            maxic = max(maxic, a[i]);
            minic = min(minic, a[i]);
        }
        for(int i=c2; i<n; i++){
            maxic = max(maxic, a[i]);
            minic = min(minic, a[i]);
        }
        if(minic==INT_MAX) ans1 = 0;
        else ans1 = maxic - minic;

        for(int i=d1; i<=d2; i++){
            maxid = max(maxid, a[i]);
            minid = min(minid, a[i]);
        }
        if(minid==INT_MAX) ans2 = 0;
        else ans2 = maxid - minid;

        cout<<ans + max(ans1, ans2)<<'\n';
    }

    return 0;
}