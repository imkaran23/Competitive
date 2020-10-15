#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        long long ans = 0;
        while(n){
            if(n%k==0){
                ans++;
                n /= k;
            }
            else{
                ans += n - (n/k)*k;
                n = (n/k)*k;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}