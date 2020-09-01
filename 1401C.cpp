#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n],b[n];
        int m = INT_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i]; 
            b[i] = a[i];
            m = min(m,a[i]);  
        }

        sort(b,b+n);
        k=0;
        for(int i = 0; i < n; i++) 
            if(a[i] != b[i] && a[i] % m > 0) k = 1;

        if(k) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}