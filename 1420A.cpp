#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        if(is_sorted(a.begin(),a.end())){
            cout<<"YES\n";
            continue;
        }
        b = a;
        sort(a.begin(),a.end(), greater<>());
        if(a==b){
            bool adj_dup = false;
            for(int i=0; i<n-1; i++){
                if(a[i]==a[i+1]){
                   adj_dup = true;
                   break; 
                }
            }

            if(adj_dup) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;
}