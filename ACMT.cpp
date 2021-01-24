#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,a,b;
    cin>>t;
    while(t--){
        cin >> a >> b;
        if(a>b) swap(a,b);
        if(b>=2*a) cout<<a<<"\n";
        else cout<<(a+b)/3<<"\n";
    }
    return 0;
    
}
