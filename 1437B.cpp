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
        int ans = 0;
        for(int i=0; i<s.size()-1; i++) if(s[i]!=s[i+1]) ans++;
        cout<<(s.size()-ans)/2<<"\n";
    }
    return 0;
}