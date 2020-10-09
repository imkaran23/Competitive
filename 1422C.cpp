// #include <bits/stdc++.h>
// using namespace std;
// long long m = 1e9 + 7;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     string s,tmp;
//     cin>>s;
//     long long n = s.size(), ans=0, x ;

//     for(int i=0; i<n; i++){
//         for(int l=1; l<=n-i; l++){
//             tmp = s.substr(0,i) + s.substr(i+l);
//             if(tmp.size()==0) break;
//             x = 0;
//             for(int j=0; j<tmp.size(); j++){
//                 x = x*10 + tmp[j] - '0';
//                 x = x%m ;
//             }
//             ans = (ans + x)%m;
//         }
//     }
    
//     cout<<ans<<endl;
//     return 0;
// }