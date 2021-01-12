#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,x;
    cin>>t;
    while(t--){
        cin>>n;
        int s1=0,s2=0,ans1=0,ans2=0;
        for (size_t i = 0; i < n; i++)
        {
            cin>>x;
            s1+=x;
            ans1 = max(ans1,s1);
        }
        
        cin>>m;
        for (size_t i = 0; i < m; i++)
        {
            cin>>x;
            s2+=x;
            ans2 = max(ans2,s2);
        }

        cout<<ans1+ans2<<"\n";
    }
    return 0;
}