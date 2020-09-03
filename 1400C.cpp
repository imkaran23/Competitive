#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x;
    string s;
    cin>>t;
    while(t--){
        cin>>s>>x;
        int n = s.size();
        string w(n,'1');
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i-x>=0) w[i-x]='0';
                if(i+x<n) w[i+x]='0';
            }
        }

        bool f=true;
        for(int i=0;i<n;i++){
            // if( s[i]=='1' && !((i-x>=0 && w[i-x]=='1') || (i+x<n && w[i-x]=='1') )) {f=false; break;}
            if(s[i]=='1'&&(i-x<0||w[i-x]=='0')&&(i+x>=n||w[i+x]=='0')) {f=false; break;}
        }
        if(f) cout<<w<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}