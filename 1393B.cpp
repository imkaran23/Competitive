#include <bits/stdc++.h>
using namespace std;
const int l = 1e5 + 5;
int a[l];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,q,sum4=0,sum2=0;
    char c;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>x;
        sum2 -= a[x]/2; 
        sum4 -= a[x]/4; 
        a[x]++;
        sum2 += a[x]/2; 
        sum4 += a[x]/4;
    }

    cin>>q;
    for(int i=0; i<q; i++){
        cin>>c>>x;
        sum2 -= a[x]/2; 
        sum4 -= a[x]/4; 
        if(c=='+') a[x]++;
        else a[x]--;
        sum2 += a[x]/2; 
        sum4 += a[x]/4;

        if(sum4>=1 && sum2>=4) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}