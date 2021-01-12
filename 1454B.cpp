#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,ans;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n+1],b[n+1];
        memset(b,0, sizeof(b));
        for(int i=1; i<=n; i++){
            cin>>a[i];
            b[a[i]]++;
        }

        bool flag = false;
        for(int i=1; i<=n; i++){
            if(b[i]==1){
                ans = i;
                flag = true;
                break;
            }
        }
        
        if(flag){
            for(int i=1; i<=n; i++){
                if(ans == a[i]){
                    cout<<i<<"\n";
                    break;
                }
            }
        }

        else cout<<-1<<"\n";
    }
    return 0;
}