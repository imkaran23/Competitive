#include<bits/stdc++.h>
using namespace std;
#define forw(i,a,b) for(int i=a; i<b; i++) 
#define ll long long int

const ll inf = 1e16;
vector<int> v;
vector<int> dp_before(5001, 0), dp_curr(5001, 0);
int cost[5001][5001];
// vector<vector<int>> cost(5001, vector<int>(5001, 0)); // 0 or inf ???
int n,k,x;


void compute(int l, int r, int optl, int optr) {
    if(l > r) return ;
    int mid = (l+r) / 2;

    pair<int, int> best = {INT_MAX, -1};
    for(int k=optl; k<=min(mid, optr); k++) {
        best = min(best, {(k==0?0:dp_before[k-1]) + cost[k][mid] , k});
    }

    dp_curr[mid] = best.first;
    int opt = best.second;

    compute(l, mid-1, optl, opt);
    compute(mid+1, r, opt, optr);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    forw(i,0,n) {
        cin>>x;
        v.push_back(x);
    }

    memset(cost, 0, sizeof(cost));
    for(int i=n-1; i>=0; i--){
        cost[i][i] = 0;

        forw(j, i+1, n)
            cost[i][j] = cost[i][j-1] + (v[i]>v[j]);

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

    for(int i = 1; i<k; i++){
        compute(0, n-1, 0, n-1);
        dp_before = dp_curr;
    }

    cout << dp_before[n-1] << '\n';

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define forw(i,a,b) for(int i=a; i<b; i++) 

// const int maxN = 5000;

// int N, K; 
// int h[maxN+1];
// vector<int> dp_cur(maxN + 1), dp_before(maxN+1);
// int d[maxN+1][maxN+1];

// // int cost(int i, int j) {
// //     return d[j][j] - d[i-1][j] - d[j][i-1] + d[i-1][i-1];
// // }

// void compute(int l, int r, int optl, int optr) {
//     if(l > r) return ;
//     int mid = (l+r) / 2;

//     pair<int, int> best = {INT_MAX, -1};
//     for(int k=optl; k<=min(mid, optr); k++) {
//         // best = min(best, {dp_before[k-1] + cost(k, mid) , k});
//         best = min(best, {dp_before[k-1] + d[k][mid] , k});
//     }

//     dp_cur[mid] = best.first;
//     int opt = best.second;

//     compute(l, mid-1, optl, opt);
//     compute(mid+1, r, opt, optr);
// }

// void init() {
//     memset(d, 0, sizeof d);

//     // for(int i=1; i<=N; i++) {
//     //     for(int j=1; j<=i; j++) {
//     //         d[i][j] = h[j] > h[i];
//     //     }
//     // }

//     // for(int i=1; i<=N; i++) {
//     //     for(int j=1; j<=N; j++) {
//     //         d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + d[i][j];
//     //     }
//     // }

//     // for(int i=1; i<=N; i++) {
//     //     dp_before[i] = cost(1, i);
//     // }

//     for(int i=N; i>0; i--){
//         d[i][i] = 0;

//         forw(j, i+1, N+1)
//             d[i][j] = d[i][j-1] + (h[i]>h[j]);

//         forw(j, i+1, N+1)
//             d[i][j] +=  d[i+1][j];
//     }

//     for(int i=1; i<=N; i++) {
//         dp_before[i] = d[1][i];
//     }
// }

// int main()
// {
//     scanf("%d%d", &N, &K);
//     for(int i=1; i<=N; i++) scanf("%d", &h[i]);
//     init();

//     // for(int i=1; i<=N; i++) cout<<dp_before[i]<<' ';
//     // cout<<'\n';

//     for(int i=2; i<=K; i++) {
//         compute(i, N, i, N);
//         dp_before = dp_cur;
//     }

//     printf("%d", dp_before[N]);
//     return 0;
// }