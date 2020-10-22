#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n], m = 0, idx = 0;
        for(int i=0; i<n; i++) cin>>a[i];

        bool check = true;
        for(int i=1; i<n; i++) if(a[i]!=a[i-1]) check = false;

        for(int i=1; i<n-1; i++){
            if((a[i]>a[i-1] || a[i]>a[i+1]) && a[i]>m){
                m = a[i];
                idx = i;
            }
        }

        if(a[0]>a[1] && a[0]>m){
            m = a[0];
            idx = 0;
        }

        if(a[n-1] > a[n-2] && a[n-1]>m){
            m = a[n-1];
            idx = n-1;
        }
        
        if(check) cout<<-1<<"\n";
        else cout<<idx+1<<"\n";
    }
    return 0;
}