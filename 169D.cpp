#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin>>n;

    int sz = 1e6+1;
    vector<int> p(sz, 1), primes;
    p[0] = p[1] = 0;

    for(ll i=2; i<=sz; i++){
        if(p[i]){
            primes.push_back(i);
            for(ll j = i*i; j<=sz; j+=i){
                p[j] = 0;
            }
        }
    }

    //logic galat hai
    ll ans = 0;
    for(ll i : primes){
        ll z = i;
        while(z<=n){
            if(n%z==0){
                n/=z;
                ans++;
            }
            cout<<z<<' ';
            z*=i;    
        }
    }

    cout<<(ans?ans:1);

    return 0;
}