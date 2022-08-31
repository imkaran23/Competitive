#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        int n, x, y;
        cin>>x>>y;

        if(x==1 && y==1) cout<<0<<'\n';
        else if(x==1 || y==1){
            cout<<max(x,y)-1 + 1<<'\n';
        }
        else{
            cout<<x-1 + y-1 + 1 + min(y-1,x-1)<<'\n';
        }
        
    }

    return 0;
}