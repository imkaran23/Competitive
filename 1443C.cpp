#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int, int> > v(n+1);
        for(int i=0; i<n; i++) cin>>v[i].first;
        for(int i=0; i<n; i++) cin>>v[i].second;

        v[n].first = v[n].second = 0;
        sort(v.begin(), v.end(), greater<>());

        long long sum = 0, ans = INT_MAX;
        for(int i = 0; i <= n; i++){
            ans = min(ans, max((long long)v[i].first, sum));
            sum += v[i].second;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// vector<pair<int,int> > a,b;

// bool comp (pair<int,int> &x, pair<int,int> &y){
//     return x.first < y.first || (x.first == y.first && a[y.second] < a[x.second]);
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n,x;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         vector<int> vis(n,0);
//         a.resize(n);
//         b.resize(n);
//         for(int i=0; i<n; i++) {
//             cin>>x;
//             a[i] = {x,i};
//         }
//         for(int i=0; i<n; i++) {
//             cin>>x;
//             b[i] = {x,i};
//         }

//         sort(b.begin(), b.end(), comp);
//         sort(a.begin(), a.end());

//         long long ans = a[n-1].first, tmp = 0, i, j;
//         for( i=0; i<n; i++){
//             tmp += b[i].first;
//             vis[b[i].second] = 1;
//             for( j=n-1; j>=0; j--){
//                 if(!vis[a[j].second]){
//                     ans = min(ans, max(tmp, (long long)a[j].first));
//                     break;
//                 }
//             }
//         }  

//         ans = min(ans, tmp);
//         cout<<ans<<"\n";  
//     }
//     return 0;
// }