#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m,q,x1,y1,x2,y2,hcf,inner,outer,ans1,ans2;
    cin>>n>>m>>q;
    hcf = __gcd(n,m);
    inner = n/hcf;
    outer = m/hcf;
    string ans;

    while(q--){
        cin>>x1>>y1>>x2>>y2;

        if(x1==1) ans1 = (y1-1)/inner;
        else ans1 = (y1-1)/outer;

        if(x2==1) ans2 = (y2-1)/inner;
        else ans2 = (y2-1)/outer;

        ans = ans1==ans2?"YES\n":"NO\n";
        cout<<ans;
    }

    return 0;
}