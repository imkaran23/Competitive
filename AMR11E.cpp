#include <bits/stdc++.h>
using namespace std;

const int m = 1e6+5;
int prime[m], nopf[m];
vector<int> lucky;

void sieve(){
	prime[0] = prime[1] = 1;
	for(int i = 2; i <= m; i++){
		if(prime[i] == 0){
			nopf[i]++;
			if(2*(1ll)*i <= m){
				for(int j = 2*i; j <= m; j += i){
					prime[j] = 1;
					nopf[j]++;
				}
			}
		}
	}

	for(int i = 30; i < m; i++) if(nopf[i] >= 3) lucky.push_back(i);
}

int main() {
    sieve();
    int t; 
    cin >> t;
    while (t--) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int n,k; 
        cin >> n; 
        cout<<lucky[n-1]<<"\n";
    }
    return 0;
}