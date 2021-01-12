#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,a,b;
    string s;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cin>>s;
        long long n = s.size(), i=0, zero = 0, ans = 0, flag = 1;
        while(n>=1 && s[n-1]=='0') n--;
        while(i<n && s[i]=='0') i++, zero++;
        while(i<n && s[i]=='1') i++;
        if(i==n){
            if(zero == n) {
                cout<<0<<"\n";
                continue;
            }
            else{
                cout<<a<<"\n";
                continue; 
            }
        }
        zero = 0;
        while(i<n){
            while(i<n && s[i]=='0') i++, zero++;
            while(i<n && s[i]=='1') i++;
            if(flag){
                flag--;
                ans = min( zero*b + a , 2*a ) ;
            }
            else
                ans = min( ans + zero*b , ans + a);
            zero = 0;       
        }
        cout<<ans<<"\n";
    }
    return 0;
}