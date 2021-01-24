#include <bits/stdc++.h>
using namespace std;

string check(string s, int k){
    string res = "";
    while (k--) res += s;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string s1,s2;
    cin>>t;
    while(t--){
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        int hcf = __gcd(n,m);
        if(check(s1,m/hcf)==check(s2,n/hcf)) cout<<check(s1,m/hcf)<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
    
}
