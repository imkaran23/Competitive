#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;

    int p[n];
    p[1] = -1;

    for(int i=2; i<=n; i++) cin>>p[i];

    int ans = 0, s = n;

    while(p[s]!=-1) s = p[s], ans++;

    cout<<ans<<"\n";    
    
    return 0;
}