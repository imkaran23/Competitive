#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    vector<int> v;
    cin>>t;
    while(t--){
        cin>>s;
        int c = 0 ;
        v.clear();
        for (int i = 0; i < s.size(); i++){
            if(s[i]=='1') c++;
            else if(c>0) {
                v.push_back(c);
                c = 0;
            }
        }
        v.push_back(c);

        sort(v.begin(), v.end(), greater <>());
        int ans = 0;
        for( int i=0 ; i<v.size() ; i+=2) ans += v[i];
        cout<<ans<<endl;
    }
}