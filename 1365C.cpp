#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int n,x,ans=0;
    cin>>n;
    int a[n],b[n]={};
    f(i,0,n-1){
        cin>>x;
        a[x] = i;
    }
    f(i,0,n-1){
        cin>>x;
        ans = max(ans,++b[(a[x]-i+n)%n]);
    }
    cout<<ans;
    return 0 ;
}