#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef tree <
	pair<int, int>,
	null_type,
	less<pair<int, int>>,
	rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;
 
int n, k, t, a[200005];
 
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> k;
	ordered_set oset;
	for (int i = 0; i < n; i++){
		int u; cin >> u; a[i] = u;
		oset.insert({u, t++});
        // cout<<"size : "<<oset.size()<<"\n";
		if (i >= k){
			oset.erase(oset.lower_bound({a[i - k], 0}));
		}
		if (i >= k - 1){
			cout << (*oset.find_by_order((k - 1) / 2)).first << ' ';
		}
	}
}