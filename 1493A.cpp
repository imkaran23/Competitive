#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k; 
        int z = k/2, tmp = k-1;
        cout<<z + (n-k>0?n-k:0)<<"\n";
        while(z--) {
            cout<<tmp<<" ";
            tmp--;
        }
        for(int i=k+1; i<=n; i++) cout<<i<<" ";
        cout<<"\n"; 
    }
}