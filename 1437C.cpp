// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n;
//     string s;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         int a[n];
//         vector<int> vis(n,0);
//         for(int i=0; i<n; i++) cin>>a[i];
//         sort(a,a+n);

//         int ans = 0;
//         unordered_set<int> s;
//         for(int i=0; i<n; i++){
//             if(s.find(a[i])==s.end()){
//                 s.insert(a[i]);
//                 vis[i] = 1;
//             } 
//         } 

//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 int k = 1;
//                 while(true){
//                     if(a[i]-k>0 && s.find(a[i]-k)==s.end()){
//                         ans += k;
//                         s.insert(a[i]-k);
//                         break;
//                     }
//                     else if(s.find(a[i]+k)==s.end()){
//                         ans += k;
//                         s.insert(a[i]+k);
//                         break;
//                     }
//                     k++;
//                 }
//             }
//         }

//         cout<<ans<<"\n";
//     }
//     return 0;
// }