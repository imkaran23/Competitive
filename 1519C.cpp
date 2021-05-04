#include <bits/stdc++.h>
using namespace std;
int n,m,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x;
    cin>>t;
    
    while(t--){
        cin>>n;
        vector<vector<long long int>> v(n+1);
        int u[n];

        for(int i=0; i<n; i++) cin>>u[i];

        for(int i=0; i<n; i++){
            cin>>x;
            v[u[i]].push_back(x);
        }

        for(int i=1; i<=n; i++) if(v[i].size()) sort(v[i].begin(), v[i].end(), greater<>());

        for(int i=1; i<=n; i++){
            for(int j=1; j<v[i].size(); j++){
                v[i][j] += v[i][j-1];
            }
        }

        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<v[i].size(); j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        for(int k=1; k<=n; k++){
            long long ans = 0;
            for(int i=1; i<=n; i++){
                if(v[i].size() > 0 && v[i].size()/k > 0){
                    int z = (v[i].size()/k) * k;
                    ans += v[i][z-1];
                    }
            }
            cout<<ans<<" ";
        }

        cout<<"\n";
    }
    return 0;
}