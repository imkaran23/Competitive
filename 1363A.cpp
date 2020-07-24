#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,a,odd=0;
        cin>>n>>x;
        f(i,1,n){
            cin>>a;
            if(a%2) odd++;
        }

        if(odd>=1 && !(x==n && odd%2==0) && !(odd==n && x%2==0)) cout<<"YES\n";
        else cout<<"NO\n"; 
    }
    return 0;
}