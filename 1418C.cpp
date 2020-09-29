#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,p,q;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0 ;i<n; i++) cin>>a[i];
        int ans = 0;
        char c = 'f';
        for(int i=0 ;i<n; i++){
            if(c=='f'){
                if(a[i]==1) ans++;
                if(i<n-1 && a[i+1]==0) i++;
                c = 'i';
            }
            else{
                if(i<n-1 && a[i+1]==1) i++;
                c = 'f';
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}