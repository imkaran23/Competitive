#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        long long res = 0;
        for(int i=0; i<n; i++) cin>>a[i];
        
        for(int i=0; i<n; i++){
            res += i*a[i] - a[i]*(n-i-1);
        }
        cout<<res<<"\n";
    }
    return 0;
    
}
