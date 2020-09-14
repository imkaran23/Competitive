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
        for(int i=0;i<n;i++) cin>>a[i];

        // for(int i=0;i<n;i++){
        //     if(a[i]>0){
        //         int mini = INT_MAX,k=n;

        //         for(int j=i+1; j<n; j++){ 
        //             if(a[j]<0 && a[j]<mini){
        //                 mini = a[j];
        //                 k = j;
        //             }
        //         }
                
        //         if(k!=n){
        //             a[i]=0;
        //             a[k]+=a[i];
        //         }
        //     }
        // }

        for(int i=0;i<n;i++){

            if(a[i]>0){
                for(int j=i+1; j<n; j++){ 
                    if(a[j]<0){
                        a[j]+=a[i];
                        a[i]=0;
                        break;
                    }
                }
            }
        }

        long long ans = 0;
        for(int i=0;i<n;i++) if(a[i]>0) ans += a[i];
        cout<<ans<<endl;
    }
    return 0;
}