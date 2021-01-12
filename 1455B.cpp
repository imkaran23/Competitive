#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        int ans = 0;
		while (ans * (ans + 1) < 2 * n) ans++;
		if (ans * (ans + 1) / 2 == n + 1) ans++;
		cout << ans << endl;
    }
    return 0;
}