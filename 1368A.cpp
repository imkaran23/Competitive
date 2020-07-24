#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,n,count=0;
        cin>>a>>b>>n;
        while(a<=n || b<=n){
            if(a<b) a+=b;
            else b+=a;
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}