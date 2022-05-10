#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;

    cin>>n>>x;

    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a,a+n);

    int ans=0,i=0,j=n-1;

    while(i<=j){
        if(i==j){
            ans++;
            break;
        }
        if(a[i]+a[j]<=x){
            i++;
            j--;
            ans++;
        }
        else{
            j--;
            ans++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}