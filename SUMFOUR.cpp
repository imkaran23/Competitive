#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n],d[n], e[n*n], f[n*n];
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    int p=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            e[p]=a[i]+b[j];
            p++;;
        }
    }
    sort(e,e+p);
    p=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            f[p]=(c[i]+d[j])*-1;
            p++;
        }
    }
    sort(f,f+p);

    int i=0, j=0, ans=0;
    while(i<n*n && j<n*n){
        int temp = j;
        bool flag = false;
        while(j<n*n && e[i] == f[j]){
            ans++;
            j++;
            flag = true;
        }
        if(flag){ 
            i++;
            j = temp;
        }
        else if(e[i]>f[j]) j++;
        else i++;
    }

    cout<<ans<<"\n";
    return 0;
}