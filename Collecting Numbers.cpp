#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++){
        cin>>x;
        a[x] = i; 
    }

    int ans = 1;
    for(int i=2; i<= n; i++){
        if(a[i-1]<a[i]) continue;
        ans++;
    }

    cout<<ans<<'\n';

    return 0;
}