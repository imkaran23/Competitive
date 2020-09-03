#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,r,g,b,w;
    cin>>t;
    while(t--){
        cin>>r>>g>>b>>w;
        int c = w%2 + r%2 + b%2 + g%2 ;
        
        cout<<( (c<2 || c>2 && r*g*b) ? "YES\n" : "NO\n" );
    }
    return 0;
}