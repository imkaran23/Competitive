#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int zero = 0, one = 0;
        for (size_t i = 0; i < s.size() ; i++) if(s[i]=='0') zero++; else one++;
        
        if(min(zero,one)%2) cout<<"DA\n";
        else cout<<"NET\n";
    }
    return 0;
}