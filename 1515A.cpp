#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        long long int n,x;
        cin>>n>>x;

        int a[n];
        long long s = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            s+=a[i];
        }

        if(n==1 && a[0]==x || s==x) cout<<"NO\n";
        else{
            long long ans = 0;
            for(int i=0; i<n-1; i++){
                if(ans + a[i] == x){
                    swap(a[i],a[i+1]);
                }
                ans += a[i];
            }

            cout<<"YES\n";
            for(int i=0; i<n; i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        
    }
    return 0;
}