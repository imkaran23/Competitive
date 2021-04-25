#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n,u,v;
        cin >> n >> u >> v; 
        int a[n];
        int ans = INT_MAX;
        for(int i=0; i<n; i++) cin>> a[i];
        for(int i=0; i<n-1; i++){
            if(abs(a[i]-a[i+1])>1) ans = 0;
            if(a[i]!=a[i+1] || (i>0 && a[i]!=a[i-1])) ans = min({ans,v,u});
        }
        
        sort(a,a+n);
        if(a[0]==a[n-1]) ans = min({ans,u+v,2*v});

        cout<<ans<<"\n";
    }
}