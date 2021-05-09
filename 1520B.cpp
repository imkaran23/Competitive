#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        if(n<10) {
            cout<<n<<"\n";
            continue;
        }
        long long int c = 0, ans, n1 = n, z;
        while(n1){
            c++;
            n1/=10;
        }

        z = n/(pow(10,c-1));
        ans = 9*(c-1) + (z-1);

        n1 = 0;
        while(c--){
            n1 = n1*10 + z;
        }

        if(n1<=n) ans++;

        cout<<ans<<"\n";
    }
    return 0;
}