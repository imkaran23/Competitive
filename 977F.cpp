#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	map<int, int> dp;
	
	int ans = 0;
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		dp[x] = dp[x - 1] + 1;
		if (ans < dp[x]) {
			ans = dp[x];
			lst = x;
		}
	}
	
	vector<int> res;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == lst) {
			res.push_back(i);
			--lst;
		}
	}
	reverse(res.begin(), res.end());
	
	printf("%d\n", ans);
	for (auto it : res)
		printf("%d ", it + 1);
	puts("");
	
	return 0;
}