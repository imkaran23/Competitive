#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b,c,x,y,z;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>x>>y>>z;
        b -= min(b,x);
        z -= min(a,z);  
        cout<<2*(min(c,y) - min(b,z))<<endl;
    }
    return 0;
}