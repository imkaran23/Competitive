#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,w,h,n;
    cin>>t;
    while(t--){
        cin>>w>>h>>n;
        long long k=1;
        while(w%2==0){
            w/=2;
            k*=2;
        }
        while(h%2==0){
            h/=2;
            k*=2;
        }
        if(k>=n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}
