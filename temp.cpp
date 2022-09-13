#include <bits/stdc++.h>
using namespace std;

#define ll long long 

vector<int> getNumPairs(vector<int> a, vector<int> queries){
   // int n;
   //  cin>>n;
   //  vector<ll> a(n);
   //  for(auto &i : a)
   //      cin>>i;

   int n = a.size();
    map<ll, ll> pref, suff;
    ll curr = 0;
    for (int i = 0; i < n; ++i)
    {
        curr = max((ll)a[i], curr);
        pref[curr]++;
    }
    curr = INT_MAX;
    for (int i = n-1; i >= 0; --i)
    {
        curr = min((ll)a[i], curr);
        suff[curr]++;
    }

   //  int q;
   //  cin>>q;

   int q = queries.size();
    vector<int> res;
    for(int i=0; i<q; i++) {
      //   cin>>n;
        n = queries[i];
        ll val = 0;
        for (int i = 1; i <= sqrt(n); ++i)
        {
            if(n % i == 0){
                if(i != n / i)
                    val += suff[i] * pref[n / i];
                val += pref[i] * suff[n / i];
            }
        }
        res.push_back(val);
    }

    return res;

   //  for(auto i : res)
   //      cout<<i<<' ';
   //  cout<<endl;
}

vector<string> split(string& s) {
   string k;
   vector<string>ans;
   for (int i = 0;i < s.size();i++) {
      if (s[i] == ' ') {
         ans.push_back(k);
         k = "";
      }
      else {
         k += s[i];
      }
   }
   ans.push_back(k);
   return ans;
}

vector<string> implementAPI(vector<string> logs) {

   unordered_map<string, int> login;
   unordered_map<string, string> reg;
   string type, user, pass;

   vector<string>ans;
   for (auto str : logs) {
      auto splitStr = split(str);

      type = splitStr[0];
      user = splitStr[1];

      if (type == "logout") {
         if (login.count(user) == 0)
            ans.push_back("Logout Unsuccessful");
         else {
            login.erase(user);
            ans.push_back("Logged Out Successfully");
         }
      }
      else {
         pass = splitStr[2];

         if (type == "register") {
            if (reg.count(user) == 0) {
               reg[user] = pass;
               ans.push_back("Registered Successfully");
            }
            else {
               ans.push_back("Username already exists");
            }
         }
         else {
            if (login.count(user) == 0 && reg.find(user)!=reg.end() && reg[user] == pass) {
               login[user] = 1;
               ans.push_back("Logged In Successfully");
            }
            else {
               ans.push_back("Login Unsuccessful");
            }
         }
      }
   }
   return ans;
}

int main(){
    int n;
    cin>>n;

    string s;
    vector<string> logs;

    while(n--){
        cin>>s;
        logs.push_back()
    }
}