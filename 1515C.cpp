#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        long long int n,m,x,y;
        cin>>n>>m>>x;

        vector<int> b(m,0), a(n), ans(n);
        long long s = 0;


        for(int i=0; i<n; i++){
            cin>>a[i];
            s+=a[i];
        }

        double z1 = s/(double)m;
        double z2 = x/(double)2;

        long long r = ceil(z1 + z2);
        long long l = ceil (z1 - z2);

        int j=0;
        for(int i=0; i<n; i++){
            if(b[j] + a[i] < l){
                ans[i] = j+1;
                b[j] += a[i];
                // cout<<j<<" "<<b[j]<<"\n";
            }
            else if(b[j] + a[i] <= r){
                ans[i] = j+1;
                b[j] += a[i];
                // cout<<j<<" "<<b[j]<<"\n";
                j++;
                j = j%m;
            }
        }

        long long s1=0;
        for(int i=0; i<m; i++) {
            s1+=b[i];
            // cout<<i<<" "<<b[i]<<" ";
        }

        // cout<<s<<" "<<s1<<" ";
        if(s==s1) {
            cout<<"YES\n";
            for(int i=0; i<n; i++) cout<<ans[i]<<" ";
            cout<<"\n"; 
        }
        else cout<<"NO\n";
    }
    return 0;
}