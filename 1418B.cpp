#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n],b[n];
        vector<int> v;
        for(int i=0 ;i<n; i++) cin>>a[i];
        for(int i=0 ;i<n; i++) cin>>b[i];
        for(int i=0 ;i<n; i++){
            if(b[i]==0) v.push_back(a[i]);
        }
        sort(v.begin(),v.end(),greater<>());
        int k = 0;
        for(int i=0 ;i<n; i++){
            if(b[i]==0){
                a[i] = v[k];
                k++;
            }
        }

        for(int i=0 ;i<n; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}