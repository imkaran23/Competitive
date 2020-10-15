#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n+2]={0};

    for(int i=2; i<n+2; i++){
        if(!a[i]){
            a[i]=1;
            for(int j=i+i; j<n+2; j+=i){
                if(!a[j]) a[j] = 2;
            }
        }
    }

    if(n<=2) cout<<1<<"\n";
    else cout<<2<<"\n";
    
    for(int i = 2; i < n+2; i ++) cout<<a[i]<<" ";
    return 0;
}