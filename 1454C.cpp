#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n), res(n + 1, 1);
		for (auto &it : a) cin >> it;
		n = unique(a.begin(), a.end()) - a.begin();
		a.resize(n);
		for (int i = 0; i < n; ++i) res[a[i]] += 1;
		res[a[0]] -= 1;
		res[a[n - 1]] -= 1;
		int ans = 1e9;
		for (int i = 0; i < n; ++i) ans = min(ans, res[a[i]]);
		cout << ans << endl;
    }
    return 0;
}