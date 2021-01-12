#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,one,two,x;
    cin>>t;
    while(t--){
        cin>>n;
        one=0,two=0;
        for(int i=0; i<n; i++){
            cin>>x;
            if(x==1) one++;
            else two++;
        }
        
        if( (one%2==0 && two%2==0) || (one>1 && one%2==0) ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    
}
