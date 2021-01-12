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
        int i=0;
        while(i+1<s.size()){
            if(s[i]=='A' && s[i+1]=='B'){
                s.erase(i,2);
                i = i-1<0?0:i-1;
            }
            else i++;
        }

        i=0;
        while(i+1<s.size()){
            if(s[i]=='B' && s[i+1]=='B'){
                s.erase(i,2);
                i = i-1<0?0:i-1;
            }
            else i++;
        }

        cout<<s.size()<<"\n";
    }
    return 0;
}