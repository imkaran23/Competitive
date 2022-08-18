#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;

        long long x = a*d, y = c*b;

        if(x == y) cout<<0<<'\n';
        else if(x==0 || y==0) cout<<1<<'\n';
        else if(x%y==0 || y%x==0) cout<<1<<'\n';
        else cout<<2<<'\n';
    }

    return 0;
}