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
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a,a+n);

        int mex;
        for(int i=0; i<n; i++){
            if(i!=a[i]){
                mex = i;
                break;
            }
        }

        if(k==0) cout<<n<<"\n";
        else if(a[n-1]==n-1) cout<<n+k<<"\n";
        else{
            int z = (a[n-1]+mex+1)/2;
            if(find(a,a+n,z)!=a+n) cout<<n<<"\n"; 
            else cout<<n+1<<"\n";
        }
    }
}