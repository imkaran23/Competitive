// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         vector<int> a(n);
//         for(int i=0; i<n; i++) cin>>a[i];  

//         for(int k=1; k<=n; k++){
//             set<int> ans;
//             for(int i=0; i<k; i++) ans.insert(a[i]);
//             for(int i=1; i<n-k+1; i++){
//                 set<int> s;
//                 vector<int> v(k);
//                 for(int j=i; j<i+k; j++) s.insert(a[j]);

//                 auto it = set_intersection(ans.begin(),ans.end(),s.begin(),s.end(), v.begin());
//                 v.resize(it-v.begin()); 
//                 ans.clear(); 
//                 for(auto x : v) ans.insert(x);
//             }

//             if(ans.empty()) cout<<-1<<" ";
//             else{
//                 int mini = INT_MAX;
//                 for(auto it= ans.begin(); it!=ans.end(); it++){mini = min(mini,*it);}
//                 cout<<mini<<" ";
//             }
//         }
//         cout<<endl;
//     }

//     return 0;
// }