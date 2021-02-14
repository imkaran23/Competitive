#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string s;
    cin>>t;
    while(t--){
        cin >> s;
        int c1=0,c2=0,c3=0,c4=0, n=s.size();

        for(int i=0; i<n; i++) if(islower(s[i])) c1++;
        for(int i=1; i<n-1; i++){
            if(isupper(s[i])) c2++;
            if(isdigit(s[i])) c3++;
            if(s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='&' || s[i]=='?') c4++;
        }

        if(n>=10 && c1>0 && c2>0 && c3>0 && c4>0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}
