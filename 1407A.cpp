// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n,x,z;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         vector<int> v(n),v1;
//         int even=0,odd=0;
//         for(int i=0;i<n;i++){
//             cin>>v[i];
//             if(i%2==0 && v[i]==1) even++;
//             else if (i%2==1 && v[i]==1) odd++; 
//         }

//         if(even-odd>0){
//             int z=0;
//             for(int i=0;i<n;i+=2){
//                 if(z==even-odd) break;
//                 else if(v[i]==1){
//                     v[i] = -1;
//                     z++;
//                 }
//             }
//         }
//         else if(odd-even>0){
//             int z=0;
//             for(int i=1;i<n;i+=2){
//                 if(z== -even+odd) break;
//                 else if(v[i]==1){
//                     v[i] = -1;
//                     z++;
//                 }
//             }
//         }

//         for(int i=0;i<n;i++) if(v[i]!=-1) v1.push_back(v[i]);
//         cout<<v1.size()<<endl;
//         for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }