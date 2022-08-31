#include <bits/stdc++.h>
using namespace std;
int par[200001];

int find(int u){
    if(u==par[u]) return u;
    return find(par[u]);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    int ans[n+1];

    for(int i=1; i<=n+1; i++) // yaha <=n pe ni chalta hai ye noobda code
        par[i] = i;

    int l[q], r[q], c[q];
    for(int i=0; i<q; i++){
        cin>>l[i]>>r[i]>>c[i];
    }

    for(int i=q-1; i>=0; i--){
        for(int j = find(l[i]); j <= r[i]; j = find(j)){
            ans[j] = c[i];
            par[j] = j+1;
        }
    }

    for(int i=1; i<=n ; i++) cout<<ans[i]<<'\n';

	return 0;
}