#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        int a[n],b[n];
        f(i,0,n-1) cin>>a[i];
        f(i,0,n-1) cin>>b[i];
        sort(b,b+n);
        if( b[0]== b[n-1] && !is_sorted(a,a+n)) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return  0;
}