// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         int t[n],x[n];
//         for (size_t i = 0; i < n; i++)
//         {
//             cin>>t[i]>>x[i];
//         }
        
//         int ans=0, time=0, nextx=0, prevx=0, c;
//         for (size_t i = 0; i < n-1; i++){
//             if(t[i]>=time){
//                 c = prevx + (t[i+1]-t[i])/x[i];
//                 if( x[i]>=c && x[i]<=prevx || x[i]>=prevx && x[i]<=c) 
//                     ans++;
//                 prevx = nextx;
//                 nextx += x[i]; 
//                 time += abs(x[i]);
//             }
//         }

//         cout<<ans<<"\n";
//     }
//     return 0;
// }