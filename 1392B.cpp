#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int64_t k,t,n;
    int maxi,mini;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        maxi = INT_MIN, mini = INT_MAX;
        for(int i=0;i<n;i++) {cin>>a[i]; maxi = max(maxi,a[i]); mini = min(mini,a[i]); }
        for(int i=0;i<n;i++) a[i] = maxi - a[i];
        if(k%2){
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
        }
        else{
            for(int i=0;i<n;i++) cout<< maxi - mini - a[i] <<" ";
            cout<<endl;
        }
    }
    return 0;
}