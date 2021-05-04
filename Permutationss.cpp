#include <bits/stdc++.h>
using namespace std;
const long long int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    
    if(n==1) cout<<1<<"\n";
    else if(n<=3) cout<<"NO SOLUTION\n";
    else{
        if(n%2){
            for(int i=1; i<=n; i+=2) cout<<i<<" ";
            for(int i=2; i<=n; i+=2) cout<<i<<" ";
            cout<<"\n";
        }
        else{
            for(int i=2; i<=n; i+=2) cout<<i<<" ";
            for(int i=1; i<=n; i+=2) cout<<i<<" ";
            cout<<"\n";
        }
    }
    return 0;
}