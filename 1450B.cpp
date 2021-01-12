#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;

        bool flag;
        for(int i=0; i<n; i++){
            flag = true;
            for(int j=0; j<n; j++){
                if(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) > k){
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }

        if(flag) cout<<1<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}