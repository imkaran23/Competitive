#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        long long s=0;
        for (size_t i = 0; i < n; i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        
        for (size_t i = 1; i < n; i+=2)
        {
            if(a[i]%a[i-1]==0 || a[i-1]%a[i]==0) cout<<a[i-1]<<" "<<a[i]<<" ";
            else{
                if(a[i-1]<a[i]){
                    int x=a[i-1], y=a[i-1];
                    while(a[i]%x!=0) x++;
                    while(a[i]%y!=0) y--;
                    if(abs(a[i-1]-x) > abs(a[i-1]-y)) a[i-1]=y;
                    else a[i-1]=x;
                }
                else{
                    int x=a[i], y=a[i];
                    while(a[i]%x!=0) x++;
                    while(a[i]%y!=0) y--;
                    if(abs(a[i]-x) > abs(a[i]-y)) a[i]=y;
                    else a[i]=x;
                }
                cout<<a[i-1]<<" "<<a[i]<<" ";
            }
        }
        if(n%2) cout<<a[n-2];
        cout<<"\n";
    }
    return 0;
}