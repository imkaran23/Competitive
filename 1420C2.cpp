// // #include <bits/stdc++.h>
// // using namespace std;

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n,q,l,r;
//     cin>>t;
//     while(t--){
//         cin>>n>>q;
//         int a[n];
//         for(int i=0; i<n; i++) cin>>a[i];
//         q++;
//         while(q--){
//             vector<int> v;
//             v.push_back(a[0]);
//             for(int i=0; i<n;){
//                 int j = i+1;
//                 if(j<n && a[j]<a[i] ){ 
//                     while(j<n && a[j]<a[i]) j++,i++;
//                     v.push_back(a[i]);
//                 }
//                 else{ 
//                     while(j<n && a[j]>a[i]) j++,i++;
//                     v.push_back(a[i]);
//                 }
//                 if(j==n) break;
//             }

//             // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";

//             if(v.size()==1) cout<<v[0]<<endl;
//             else{
//                 long long ans = 0;
//                 if(v[0]>v[1]){
//                     ans = v[0];
//                     for(int i=1; i+1<v.size(); i+=2) ans = max(ans, ans + (long long)(v[i+1]-v[i]));
//                 }
//                 else{
//                     ans = v[1];
//                     for(int i=2; i+1<v.size(); i+=2) ans = max(ans, ans + (long long)(v[i+1]-v[i]));
//                 }

//                 cout<<ans<<endl;
//             }

//             cin>>l>>r;
//             swap(a[l-1],a[r-1]);
//         }
        
//     }
//     return 0;
// }