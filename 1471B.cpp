#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,i,j;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int a[n],b[n];
        long long int sum = 0;
        for ( i = 0; i < n; i++) {
            cin>>a[i]; 
            b[i]=a[i];
            sum+=a[i];
        }

        for ( i = 0; ; i++) {
            i = i%n;
            if(b[i]%x==0){
                sum+=a[i];
                b[i]/=x;
            }
            else break;
        }

        cout<<sum<<"\n";
    }
    return 0; 
}
