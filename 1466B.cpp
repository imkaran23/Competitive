#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0; i<n ; i++){
            cin>>a[i];
        }
        if(n==1) cout<<1<<"\n";
        else{
            int ans=1;
            for(int i=1; i<n ; i++){
                if(a[i]<a[i-1]){ 
                    a[i]++;
                    continue;
                }
                if(a[i]>a[i-1]) ans++;
                else {
                    a[i]++;
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}