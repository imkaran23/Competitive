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
        sort(s.begin(), s.end());
        cout<<s<<"\n";
    }
    return 0;
}