#include <bits/stdc++.h>
using namespace std;
const long long int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T --) {
        int l,r;
        cin>>l>>r;
        
        long long int sum = 0, ans=0;
        for(int i=l;i<=r;i++) sum+=i;
        
        for(int i=l;i<=r;i++){
            sum-=i;
            ans += (i * sum%m)%m;
        }

        cout<<(2*ans)%m<<"\n";
    }
    return 0;
}