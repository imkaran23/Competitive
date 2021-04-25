#include <bits/stdc++.h>
using namespace std;

const int me = 10000025;
const int mod = 1000000007;

int phi[me], prime[me], f[me], fact[me];

void computeTotient() {  
    for (int i=1; i<=me; i++) 
        phi[i] = i;
 
    for (int p=2; p<=me; p++) { 
        if (phi[p] == p) { 
            phi[p] = p-1; 
            for (int i = 2*p; i<=me; i += p) {  
                phi[i] = (phi[i]/p) * (p-1); 
            } 
        } 
    } 
} 

void computePrime() {
    for(int i = 2; i < me; i ++){
        if(!prime[i]){
            for(int j = i + i; j < me; j += i){
                prime[j] = 1;
            }
        }
    }
    for(int i = 2; i < me; i ++){
        prime[i] = prime[i - 1] + 1 - prime[i];
    }
}

int power(int a, int b){
    if(b == 0){
        return 1 % mod;
    }
    if(b & 1){
        return 1LL * power(a, b - 1) * a % mod;
    }
    int half = power(a, b >> 1);
    return 1LL * half * half % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computeTotient();
    computePrime();
    for(int i = 1; i < me; i ++){
        f[i] = prime[i] - phi[i];
        if(f[i] < 0){
            f[i] = 0;
        }
    }

    fact[0] = 1;
    for(int i = 1; i < me; i ++){
        fact[i] = 1LL * fact[i - 1] * i % (mod - 1);
    }

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout << power(phi[n], fact[f[n]]) << "\n";
    }
}