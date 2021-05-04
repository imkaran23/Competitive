#include <bits/stdc++.h>
using namespace std;
const long long int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++) cin>>a[i];

    long long int ans = 0; 
    for(int i=1; i<n; i++){
        if(a[i]<a[i-1]){
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }

    cout<<ans<<"\n";
    return 0;
}