#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        int mini = INT_MAX,j;
        for(int i=0; i<n; i++){ 
            cin>>a[i];
            if(a[i]<mini){
                mini = a[i];
                j = i;
            }    
        }
        a.erase(a.begin()+j);
        long long ans = 0;

        for(int i=0; i<n-1; i++){
            ans += (k-a[i])/mini;
        }

        cout<<ans<<endl;
    }
    return 0;
}