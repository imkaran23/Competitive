#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin>>a[i];
        for (int i = 0; i < m; i++) cin>>b[i];
        sort(a,a+n, greater<>());

        long long sum = 0, k=0;
        for (int i = 0; i < n; i++){
            if(k<a[i]-1){
                sum+=b[k];
                k++;
            }
            else sum+=b[a[i]-1];
        }
        cout<<sum<<"\n";
    }
    return 0;
    
}
