#include <bits/stdc++.h>
using namespace std;

const int m = 1e6+5;
int prime[m];
vector<int> v={1};

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
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int d; 
        cin >> d; 
        int ans = 1, k = 1, count = 0;
        for(int i=1;i<m;i++){
            if(count==2) break;
            if(v[i]-k>=d){
                ans *= v[i];
                k = v[i];
                count++;
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}