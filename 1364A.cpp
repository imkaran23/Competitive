#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,ans=-1,sum=0,m;
        cin>>n>>x;
        f(i,0,n-1){
            cin>>m;
            sum += m;
            if(sum%x) ans = max({ans,i+1,n-i-1});
        }
        cout<<ans<<endl;
    }
}