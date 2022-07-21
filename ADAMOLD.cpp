#include<bits/stdc++.h>
using namespace std;
#define forw(i,a,b) for(int i=a; i<b; i++) 
#define ll long long int

const ll inf = 1e16;
vector<ll> v;
vector<ll> dp_before(5001, 0), dp_curr(5001, 0);
vector<vector<ll>> cost(5001, vector<ll>(5001, inf));
int n,k,x;


void compute(int l, int r, int optl, int optr){
    if(l>r) return;
    int mid = (l+r)>>1;

    // pair<ll,ll> best = {cost[0][mid], -1};
    pair<ll,ll> best = {inf, -1};


    for(int k = optl; k<=min(mid,optr); k++){
        // best = min(best, { dp_before[k] + cost[k+1][mid] , k});
        best = min(best, { (k>0 ? dp_before[k-1] : 0) + cost[k][mid] , k});
    }
    
    dp_curr[mid] = best.first;
    int opt = best.second;

    cout<<l<<' '<<r<<' '<<optl<<' '<<optr<<' '<<dp_curr[mid]<<' '<<opt<<'\n';

    compute(l, mid-1, optl, opt);
    compute(mid+1, r, opt, optr);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    forw(i,0,n) {
        cin>>x;
        v.push_back(x);
    }

    for(int i=n-1; i>=0; i--){
        cost[i][i] = 0;

        forw(j, i+1, n)
            cost[i][j] = cost[i][j-1] + (v[i]^v[j]);

        forw(j, i+1, n)
            cost[i][j] +=  cost[i+1][j];
    }

    // forw(i,0,n){
    //     forw(j,0,n){
    //         cout<<cost[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    forw(i, 0, n) dp_before[i] =  cost[0][i];

    for(int i = 1; i<=k; i++){
        compute(0, n-1, 0, n-1);
        dp_before = dp_curr;
    }

    cout << dp_before[n-1] << '\n';

    return 0;
}