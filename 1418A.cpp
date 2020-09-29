#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,y,k;
    cin>>t;
    while(t--){
        cin>>x>>y>>k;
        unsigned long long total = k*(1+y), ans  = k + 1, stick = x;
        while(stick*x<total){
            ans += stick;
            stick *=x;
            cout<<stick<<endl;
        }
        total -= stick;
        ans += total/x ;
        total -= total/x;
        ans += (total%x==0?0:1) ;  
        cout<<ans<<endl;
    }
    return 0;
}