#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    string s;
    map<string,int> mp;

    for(int i=0; i<n; i++){
        cin>>s;
        if(mp.find(s)!=mp.end()){
            int x = mp[s];
            cout<<s<<'('<<x<<')'<<'\n';
        }
        else 
            cout<<s<<'\n';

        mp[s]++;
    }

    return 0;
}