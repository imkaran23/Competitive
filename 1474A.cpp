#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int n; 
        cin >> n; 
        string a="1",b,s;
        cin>>b;
        s = b[0]=='0'?"1":"2";
        for(int i=1;i<n;i++){
            if(s[i-1]=='2'){
                if(b[i]=='0') a+="1";
                else  a+="0";
                s+="1";
            }
            else if(s[i-1]=='1'){
                if(b[i]=='0') a+="0",s+="0";
                else a+="1",s+="2";
            }
            else{
                if(b[i]=='0') a+="1",s+="1";
                else a+="1",s+="2";
            }
        }
        cout<<a<<"\n";
    }
    return 0;
}