#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n && n!=0){ 
        long long ans = 1,a=1;
        for(int i=1;i<=n;i++){
            a += 3;
            ans += a; 
        }
        cout<<ans<<"\n";
    }
    return 0;
}