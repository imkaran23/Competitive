#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long f=1;
    for(int i=2; i<=n; i++) f*=i;

    cout<<(2*f)/n/n<<"\n";
    return 0;
}