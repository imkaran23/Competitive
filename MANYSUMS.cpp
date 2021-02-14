#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t,l,r;
    cin>>t;
    while(t--){
        cin >> l >> r;
        l *=2;
        r *=2;
        cout<<r-l+1<<"\n";
    }
    return 0;  
}
