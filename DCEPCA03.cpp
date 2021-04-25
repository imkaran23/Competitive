#include <bits/stdc++.h>
using namespace std;

const int me = 10025;

int phi[me], h[me];

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

    for(int i=2; i<=me; i++){
        phi[i] += phi[i-1]; 
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    computeTotient();
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout << 1LL * phi[n] * phi[n] << "\n";
    }
}