#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        long long int n,l,r,x,l1=0,r1=0,y;
        cin>>n>>l>>r;

        int a[n+1][2];
        memset(a,0,sizeof(a));

        for(int i=0; i<l; i++){
            cin>>x;
            a[x][0]++;
        }

        for(int i=0; i<r; i++){
            cin>>x;
            a[x][1]++;
        }

        long long int ans = 0;
        for(int i=1; i<n+1; i++){
            // cout<<a[i][0]<<" "<<a[i][1]<<"\n";
            if(a[i][0]!=a[i][1]){
                y = abs(a[i][0]-a[i][1]);
                if(y%2){
                    if(a[i][0]>a[i][1]) l1++;
                    else r1++;
                }
                ans += y/2;
            }
        }

        y = min(l1,r1);
        l1-=y;
        r1-=y;

        ans = ans + y + l1 + r1; 

        cout<<ans<<"\n";
    }
    return 0;
}