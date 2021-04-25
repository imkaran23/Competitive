#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, zero=0, one=0;
    cin>>n>>q;
    int a[n];
    for(int i=0; i<n; i++) {cin>>a[i]; if(a[i]==1) one++; else zero++;}
    while(q--){
        int t,b;
        cin>>t>>b;
        if(t==1){
            b--;
            if(a[b]==1) one--,zero++; else zero--,one++;
            a[b] = 1 - a[b];
        }
        else{
            if(b<=one) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
    }
}