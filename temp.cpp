#include <bits/stdc++.h>
using namespace std;

// int MaxSubarraySum(vector<int> nums, int k){
//    unordered_map<int, int> mp;
//    deque<int> tmp;

//    int n = nums.size(), sum = 0, ans = 0, l =0;
//    for(int i=0; i<k; i++){
//       mp[nums[i]]++;
//       tmp.push_back(nums[i]);
//       sum += nums[i];
//    }

//    for(int i=k; i<n; i++){
//       if(tmp.size()==mp.size()) ans = max(ans, sum);

//       sum -= tmp.front();
//       tmp.pop_front();
//       mp[nums[l]]--;
//       if(mp[nums[i]]==0) mp.erase(nums[l]);
//       l++;
      
//       sum += nums[i];
//       tmp.push_back(nums[i]);
//       mp[nums[i]]++;
//    }

//    return ans;
// }

// int main(){
//    cout<<"hi";
//    return 0;
// }

// int dp[501][1001][11];

// int recur(int m, vector<int>& p, vector<int>& n, int k, int i){
//    if(i<0) return 0;

//    if(dp[i][m][k]!=-1) return dp[i][m][k];

//    int tmp = 0;

//    if(p[i]<=m){
//       tmp = max(tmp, n[i] + recur(m-p[i], p, n, k, i-1));
//       tmp = max(tmp, recur(m, p, n, k, i-1));
//       if(k>0) tmp = max(tmp, n[i] + recur(m- (p[i]/2), p, n, k-1, i-1));
//    }
//    else if(p[i]/2<=m){
//       tmp = max(tmp, recur(m, p, n, k, i-1));
//       if(k>0) tmp = max(tmp, n[i] + recur(m - (p[i]/2), p, n, k-1, i-1));
//    }
//    else {
//       tmp = max(tmp, recur(m, p, n, k, i-1));
//    }
      
//    return dp[i][m][k] = tmp;
// }

// int getAns(int m, vector<int> price, vector<int> nutrition, int k){
//    memset(dp, -1, sizeof(dp));
//    int n = price.size();
//    return recur(m, price, nutrition, k, n-1); 
// }

// int main(){
//    int m, k, n;
//    cin>>n>>m>>k;

//    vector<int> p(n), nut(n);
//    for(int i=0; i<n; i++){
//       cin>>p[i];
//    }

//    for(int i=0; i<n; i++){
//       cin>>nut[i];
//    }

//    cout<<getAns(m, p, nut, k)<<'\n';
//    return 0;
// }

// #define ll long long 

// vector<int> getNumPairs(vector<int> a, vector<int> queries){
//    // int n;
//    //  cin>>n;
//    //  vector<ll> a(n);
//    //  for(auto &i : a)
//    //      cin>>i;

//    int n = a.size();
//     map<ll, ll> pref, suff;
//     ll curr = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         curr = max((ll)a[i], curr);
//         pref[curr]++;
//     }
//     curr = INT_MAX;
//     for (int i = n-1; i >= 0; --i)
//     {
//         curr = min((ll)a[i], curr);
//         suff[curr]++;
//     }

//    //  int q;
//    //  cin>>q;

//    int q = queries.size();
//     vector<int> res;
//     for(int i=0; i<q; i++) {
//       //   cin>>n;
//         n = queries[i];
//         ll val = 0;
//         for (int i = 1; i <= sqrt(n); ++i)
//         {
//             if(n % i == 0){
//                 if(i != n / i)
//                     val += suff[i] * pref[n / i];
//                 val += pref[i] * suff[n / i];
//             }
//         }
//         res.push_back(val);
//     }

//     return res;

//    //  for(auto i : res)
//    //      cout<<i<<' ';
//    //  cout<<endl;
// }

// vector<string> split(string& s) {
//    string k;
//    vector<string>ans;
//    for (int i = 0;i < s.size();i++) {
//       if (s[i] == ' ') {
//          ans.push_back(k);
//          k = "";
//       }
//       else {
//          k += s[i];
//       }
//    }
//    ans.push_back(k);
//    return ans;
// }

// vector<string> implementAPI(vector<string> logs) {

//    unordered_map<string, int> login;
//    unordered_map<string, string> reg;
//    string type, user, pass;

//    vector<string>ans;
//    for (auto str : logs) {
//       auto splitStr = split(str);

//       type = splitStr[0];
//       user = splitStr[1];

//       if (type == "logout") {
//          if (login.count(user) == 0)
//             ans.push_back("Logout Unsuccessful");
//          else {
//             login.erase(user);
//             ans.push_back("Logged Out Successfully");
//          }
//       }
//       else {
//          pass = splitStr[2];

//          if (type == "register") {
//             if (reg.count(user) == 0) {
//                reg[user] = pass;
//                ans.push_back("Registered Successfully");
//             }
//             else {
//                ans.push_back("Username already exists");
//             }
//          }
//          else {
//             if (login.count(user) == 0 && reg.find(user)!=reg.end() && reg[user] == pass) {
//                login[user] = 1;
//                ans.push_back("Logged In Successfully");
//             }
//             else {
//                ans.push_back("Login Unsuccessful");
//             }
//          }
//       }
//    }
//    return ans;
// }

// int main(){
//     int n;
//     cin>>n;

//     string s;
//     vector<string> logs;

//     while(n--){
//         cin>>s;
//         logs.push_back()
//     }
// }