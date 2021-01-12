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
        for (size_t i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        int l =0, r=n-1;
        while(l<=r){
            if(l==r){ cout<<a[l]<<" ";}
            else {cout<<a[l]<<" "<<a[r]<<" ";}
            l++,r--;
        }
        
        cout<<"\n";
    }
    return 0;
}