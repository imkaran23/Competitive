#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        long long int a,b,n,y,z,z1;
        bool flag = true;
        cin>>a>>b>>n;
        int ar[n],br[n];
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) cin>>ar[i];
        for (int i = 0; i < n; i++)
        {
            cin>>br[i];
            v.push_back({ar[i],br[i]});
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < n; i++){
            z=v[i].second;
            z1=v[i].first;
            if(z>0 && b>0){
                y = z/a;
                if(b-y*z1>=0){
                    b-=y*z1;
                    z-=y*a;
                }
                while(b>0 && z>0){
                    z-=a;
                    b-=z1;
                }
            }
            if(z>0) flag = false;
        }

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}