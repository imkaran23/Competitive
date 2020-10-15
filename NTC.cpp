#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m,x;
    cin>>n>>k>>m;
    vector<vector<int> > remainder(m);

    for(int i=0; i<n; i++){ 
        cin>>x;
        remainder[x%m].push_back(x);
    }

    bool possible = false;
    for(int i=0; i<m; i++){
        if(remainder[i].size()>=k){
            cout<<"Yes\n";
            for(int j=0; j<k ; j++) cout<<remainder[i][j]<<" ";
            possible = true;
            break;
        }
    }

    if(!possible) cout<<"No\n";
    return 0;
}