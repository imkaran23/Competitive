#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.size();
        if(s[0]==')' || s[n-1]=='(' || n%2) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}