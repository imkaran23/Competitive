// #include <bits/stdc++.h>
// using namespace std;
// unordered_map<string, int> mp;

// int recur(string s, int c, int  &ans){
//     cout<<s<<" "<<c<<" "<<ans<<"\n";
//     if(s.size()==0) return c;
//     if(mp.find(s)!=mp.end()) return mp[s];
//     mp[s] = c;
//     ans = max(c,ans);

//     for(int i=0; i<s.size(); i++){
//         char ch = s[i];
//         string sc = s;
//         sc.erase(sc.begin()+i);
//         if(sc.size()==0) return c+1;
//         if(ch=='1'){
//             int onep=0;
//             while(onep<sc.size()) { if(sc[onep]=='1') onep++; else break;}
//             if(onep==sc.size()) return c+1;
//             int t = recur(sc.substr(onep), c+1, ans);
//         }
//         else{
//             int zerop=0;
//             while(zerop<sc.size()) { if(sc[zerop]=='0') zerop++; else break;}
//             if(zerop==sc.size()) return c+1;
//             int t = recur(sc.substr(zerop), c+1, ans);
//         }
        
//     }

//     return ans;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n;
//     string s;
//     cin>>t;
//     while(t--){
//         cin>>n>>s;
//         int ans = 0;
//         mp.clear();
//         if(s.size()==1) cout<<1<<endl;
//         else cout<<recur(s,0,ans)<<endl;
//         // cout<<ans<<endl;
//     }
//     return 0;
// }