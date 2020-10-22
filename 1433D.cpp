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
        for(int i=0; i<n; i++) cin>>a[i];

        vector<pair<int,int>> v;
        vector<int> vis(n,0);

        for(int i=0; i<n ; i++){
            for(int j=0; j<n ; j++){
                if( vis[j]==0 && a[j]!=a[i] ) {
                    vis[i] = 1;
                    vis[j] = 1;
                    v.push_back(make_pair(i+1,j+1));
                }
            }
        }

        if(v.size()==n-1){
            cout<<"YES\n";
            for(int i = 0; i<n-1; i++) cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}