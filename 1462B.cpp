#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        if( s.substr(0,4) == "2020" || s.substr(n-4,4) == "2020" ||
            (s.substr(0,3) == "202" && s.substr(n-1,1) == "0")  ||
            (s.substr(0,2) == "20" && s.substr(n-2,2) == "20")  ||
            (s.substr(0,1) == "2" && s.substr(n-3,3) == "020")
            )
        cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}