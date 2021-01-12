#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a[3];
    cin>>t;
    while(t--){
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        
        if((a+b+c)%6==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}