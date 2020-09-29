#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        int a[32] = {0};
        long long ans = 0;
        for(int i=0; i<n; i++){
            cin>>x;
            ans += a[(int)log2(x)]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}