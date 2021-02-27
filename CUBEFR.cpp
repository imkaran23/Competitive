#include <bits/stdc++.h>
using namespace std;
const int m = 1e6 + 1;
int a[m];

void sieve(){
    for(int i=2; i<=cbrt(m); i++){
        int k = i*i*i;
        if(a[i]==0){
            for(int j=k; j<m; j+=k){
                a[j]=1;
            }
        } 
    }

    for(int i=1; i<m; i++) a[i]+=a[i-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    for(int i=1; i<=t; i++) { 
        int n;
        cin >> n;
        if(a[n]==a[n-1])
            cout<< "Case "<<i<<": " << n-a[n] << "\n";
        else
            cout<< "Case "<<i<<": Not Cube Free" << "\n";
    }
}