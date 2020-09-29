#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        if(n<=2){ cout<<1<<endl; continue;}
        int ans = 1 + (n-2)/x + ((n-2)%x?1:0);
        cout<<ans<<endl;
    }
    return 0;
}