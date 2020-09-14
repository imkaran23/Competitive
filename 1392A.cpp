#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        bool ans = true;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i && a[i] != a[i-1]) ans = false;
        }
        if(ans) cout<<n<<endl;
        else cout<<1<<endl;
    }
    return 0;
}