#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k>n) cout<<k-n<<endl;
        else{
            if((n-k)%2==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}