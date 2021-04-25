#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n; 
        int a[101];
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++) {cin>>k; a[k]++;}
        for(int i=0; i<101; i++) {
            if(a[i]){
                cout<<i<<" ";
                a[i]--;
            }
        }

        for(int i=0; i<101; i++) {
            while(a[i]--){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
}