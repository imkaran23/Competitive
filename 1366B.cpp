#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,m,l,r;
        cin>>n>>x>>m;
        l = r = x; 
        while(m--){
            int a,b;
            cin>>a>>b;
            if(b>=l && a<=r) l = min(a,l), r=max(b,r);
        }
        cout<<r-l+1<<endl;
    }
    return 0;
}