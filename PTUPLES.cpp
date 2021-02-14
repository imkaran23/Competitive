#include <bits/stdc++.h>
using namespace std;

const int m = 1e6+1;
int prime[m];
vector<int> v;
void sieve(){
	prime[0] = prime[1] = 1;
	for(int i = 2; i <= m; i++){
		if(prime[i] == 0){
            v.push_back(i);
			if(2*(1ll)*i <= m){
				for(int j = 2*i; j <= m; j += i){
					prime[j] = 1;
				}
			}
		}
	}
}

int main() {
    sieve();
    int t; 
    cin >> t;
    while (t--) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n, ans = 0 ; 
        cin >> n; 
        int z = v.size();
        for(int i=1;i<z;i++){
            if(v[i]+2>n) break;
            if(prime[v[i]+2]==0) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}