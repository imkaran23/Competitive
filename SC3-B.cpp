#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++) a[i] += a[i-1];

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        cout<<lower_bound(a, a + n, x) - a +1<<"\n";
    }
    return 0;
}