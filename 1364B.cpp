#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        vector<int> v;
        f(i,0,n-1) cin>>a[i];
        f(i,0,n-1){
            if( i==0 || i==n-1 || ( a[i-1]<a[i] != a[i]<a[i+1] )) v.push_back(a[i]);
        }
        cout<<v.size()<<endl;
        for(int i : v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}