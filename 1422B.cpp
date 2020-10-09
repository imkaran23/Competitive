// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n,m;
//     cin>>t;
//     while(t--){
//         cin>>n>>m;
//         int a[n][m];
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 cin>>a[i][j];
//             }
//         }

//         long long ans = 0;
//         for(int i=0; i<n/2; i++){
//             for(int j=0; j<m/2; j++){
//                 long long x=a[i][j], w=a[i][m-1-j], y=a[n-1-i][j], z=a[n-1-i][m-1-j];
//                 long long c = (x+y+z+w)/4, tmp= INT64_MAX;
//                 for(int k=0; k<4; k++) tmp = min(tmp, (abs(x-c-k) +  abs(w-c-k) + abs(y-c-k) + abs(z-c-k) ));
//                 ans += tmp;
//             }
//         }

//         if(n%2){
//             for(int j=0; j<m/2; j++){
//                 long long x=a[n/2][j], w=a[n/2][m-1-j];
//                 ans += abs(x-w);
//             }
//         }

//         if(m%2){
//             for(int i=0; i<n/2; i++){
//                 long long x=a[i][m/2], y=a[n-1-i][m/2];
//                 ans += abs(x-y);
//             }
//         }

//         cout<<ans<<endl;
//     }
//     return 0;
// }