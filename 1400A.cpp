#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s,ans;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        ans = "";
        for(int i=0;i<s.size();i+=2) ans+=s[i];
        cout<<ans<<endl;
    }
    return 0;
}