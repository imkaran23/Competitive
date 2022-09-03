#include<bits/stdc++.h>
using namespace std;

const int maxD = 30, maxN = 2e5+5;
int go_up[maxN][maxD]; // log2(10^9) = 30

int jump(int x, int k){
    for(int i=0; i<maxD; i++){
        if(1<<i & k){
            x = go_up[x][i]; 
        }
    }
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        cin>>go_up[i][0];
    }

    for(int i=1; i<maxD; i++){
        for(int j=1; j<=n; j++){
            go_up[j][i] = go_up[go_up[j][i-1]][i-1];
        }
    }

    while(q--){
        int x,k;
        cin>>x>>k;
        cout<<jump(x, k)<<'\n';
    }
    return 0;
}