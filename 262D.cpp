#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,l,r;
    cin>>n>>l>>r;

    int a[n];

    for(int i = 0; i<n; i++) cin>>a[i];

    int p[n];
    p[0] = a[0];

    for(int i=1; i<n; i++){
        p[i] = 0;
        p[i] += p[i-1] + a[i];
    }

    // for(int i=0; i<n; i++) cout<<p[i]<<' ';
    // cout<<'\n';

    // for(int i = n-1; i>=0; i--){
    //     if(p[i] > (i+1)*l){
    //         cout<<i<<"\n";
    //         for(int j = 0; j<=i; j++) a[j] = l;
    //         break;
    //     }
    // }

    int idx = -1;
    for(int i = 0; i<n; i++){
        if(p[i] > (i+1)*l){
            idx = i;
            cout<<i<<"\n";
            // for(int j = 0; j<=i; j++) a[j] = l;
            // break;
        }
        else{
            if(idx != -1){
                for(int j = 0; j<=idx; j++) a[j] = l;
            }
            break;
        }
    }

    for(int i=0; i<n; i++) cout<<a[i]<<' ';
    cout<<'\n';

    p[n-1] = a[n-1];

    for(int i = n-2; i>=0; i--){
        p[i] = 0;
        p[i] += p[i+1] + a[i];
    }

    // for(int i=0; i<n; i++) cout<<p[i]<<' ';
    // cout<<'\n';

    // for(int i = 0; i<n; i++){
    //     if(p[i] > (n-i)*r){
    //         cout<<i<<"\n";
    //         for(int j = i; j<n; j++) a[j] = r;
    //         break;
    //     }
    // }

    idx = -1;
    for(int i = n-1; i>=0; i--){
        if(p[i] > (n-i)*r){
            idx = i;
            cout<<i<<"\n";            
        }
        else{
            if(idx != -1){
                for(int j = idx; j<n; j++) a[j] = r;
            }
            break;
        }
    }

    for(int i=0; i<n; i++) cout<<a[i]<<' ';
    cout<<'\n';

    int ans = 0;
    for(int i=0; i<n; i++){ 
        ans += a[i];
    }

    cout<<ans<<'\n';

    return 0;
}