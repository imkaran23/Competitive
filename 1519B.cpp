#include <bits/stdc++.h>
using namespace std;
int n,m,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        cin>>n>>m>>k;
        if(k==n*m-1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}