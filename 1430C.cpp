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
        for(int i=0; i<n; i++) a[i] = i+1;
        cout<<2<<endl<<a[n-1]<<" "<<a[n-2]<<endl;
        a[n-2] = (a[n-2] + a[n-1])/2 + 1;
        for(int i=n-3; i>=0; i--){
            cout<<a[i]<<" "<<a[i+1]<<endl;
            a[i] = (a[i] + a[i+1])/2;
        }
    }
    return 0;
}