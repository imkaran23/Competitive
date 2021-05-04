#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        long long int n;
        cin>>n;

        double z1 = sqrt(n/(double)2);
        double z2 = sqrt(n/(double)4);

        if( ceil (z1) == floor(z1) ||
            ceil (z2) == floor(z2))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}