#include <bits/stdc++.h>
using namespace std;
const long long int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    while (n!=1){
        cout<<n<<" ";
        if(n%2==0){
            n/=2;
        }
        else {
            n = 3*n + 1;
        }
    }

    cout<<1<<"\n";
    return 0;
}