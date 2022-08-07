#include <bits/stdc++.h>
using namespace std;

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