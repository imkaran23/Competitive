#include <bits/stdc++.h>
using namespace std;
const long long int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n-1];
    for(int i=0; i<n-1; i++) cin>>a[i];
    
    sort(a,a+n-1);

    int i;
    for(i=1; i<n; i++){
        if(a[i-1]!=i)
            break;
    }

    cout<<i<<"\n";
    return 0;
}