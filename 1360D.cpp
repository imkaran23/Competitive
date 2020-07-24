#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,k;
	cin>>t;

	while(t--){
        cin>>n>>k;
        if(k>=n) cout<<1<<'\n'; 
        else{
            int ans = n;
            for (int j = 1; j * j <= n; j++) {
                if (n % j == 0) {
                    if (j <= k) ans = min(ans, n / j);
                    if (n / j <= k) ans = min(ans, j);
                }
            }
            cout << ans << '\n';
        }
    }
    
}