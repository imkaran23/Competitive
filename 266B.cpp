#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    cin>>n;

    long long rem = n%998244353;
    long long div = n/998244353;
    if(n>0){
        cout<<rem;
    }
    else{
        cout<< (n - (div-1)*998244353)%998244353;
    }
    

    return 0;
}