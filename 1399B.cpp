#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,min_a,min_b,ans;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n],b[n];
        min_a=INT_MAX,min_b=INT_MAX;
        for(int i=0; i<n; i++){ 
            cin>>a[i];
            if(a[i]<min_a) min_a=a[i];
        }
        for(int i=0; i<n; i++){ 
            cin>>b[i];
            if(b[i]<min_b) min_b=b[i];
        }

        ans=0;
        for(int i=0; i<n; i++){
            ans += max(a[i]-min_a,b[i]-min_b);
        }
        cout<<ans<<endl;
    }
}