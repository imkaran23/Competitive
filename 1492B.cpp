#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n;
        cin >> n; 
        int used[n+1];
        vector<int> a(n);
        for(int i=0; i<=n; i++) used[i] = 0;
        for(int i=0; i<n; i++) cin>>a[i];

        int m = n, k = n-1;
        for(int i=n-1; i>=0; i--){
            used[a[i]]=1;
            if(a[i]==m){
                for(int j=i; j<=k; j++) cout<<a[j]<<" ";
                k=i-1;
                --m;
                while(used[m]==1) --m;
            }
        }
        cout<<"\n";
    }
}