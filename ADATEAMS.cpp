#include <bits/stdc++.h>
using namespace std;
const int n = 1000025, mod = 1000000007;

int N, A, B, D, factorial[n], inverse_factorial[n];

int binary_power(int a, int b){
    if(b == 0)
        return 1;
    if(b & 1)
        return 1LL * binary_power(a, b - 1) * a % mod;
    int half = binary_power(a, b >> 1);
    return 1LL * half * half % mod;
}
int nCr(int n, int k){
    return 1LL * factorial[n] * inverse_factorial[k] % mod * inverse_factorial[n - k] % mod;
}

int main() {
    
    factorial[0] = inverse_factorial[0] = 1;
    for(int i = 1; i < n; i ++){
        factorial[i] = 1LL * factorial[i - 1] * i % mod;
        inverse_factorial[i] = binary_power(factorial[i], mod - 2);
    }
    
    while(scanf("%d %d %d %d", &N, &A, &B, &D) != EOF){
        cout << 1LL * nCr(N, A) * binary_power(nCr(B, D), A) % mod << "\n";
    }
    
    return 0;
}