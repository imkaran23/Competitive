#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k=1;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){ 
        cin>>a[i]; 
    }
    sort(a,a+n);
    
    long long sum=0,ans=1e18;
    while(pow(k,n-1)<=pow(10,10)) k++;
    for(int i=1; i<k; i++){
        sum=a[0]-1;
        for(int j=1;j<n;j++){
            sum += abs((long long)a[j] - (long long)pow(i,j));
        }
        ans = min(ans,sum);
    }

    cout<<ans<<endl;
    return 0;
}