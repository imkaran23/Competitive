#include <bits/stdc++.h>
using namespace std;

bool isBalancedExp(string exp) {
   stack<char> stk;
   char x;
   for (int i=0; i<exp.length(); i++) {
      if (exp[i]=='('||exp[i]=='['||exp[i]=='{') {
         stk.push(exp[i]);
         continue;
      }
      if (stk.empty())
         return false;
      switch (exp[i]) {
      case ')':
         x = stk.top();
         stk.pop();
         if (x=='{' || x=='[')
            return false;
         break;
      case '}':
         x = stk.top();
         stk.pop();
         if (x=='(' || x=='[')
            return false;
         break;
      case ']':
         x = stk.top();
         stk.pop();
         if (x =='(' || x == '{')
            return false;
         break;
      }
   }
   return (stk.empty());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        string s;
        cin>>s;
        char c1 = s[0], c2 = s[s.size()-1];

        int n = s.size(), cnt1=0, cnt2=0;
        string s1;
        s1.resize(n);

        for(int i=0; i<n; i++){
            if(s[i]==c1) s1[i] = '(', cnt1++;
            else if(s[i]==c2) s1[i] = ')', cnt2++;
            else s1[i] = '-';
        }

        if(cnt1<cnt2){
            for(int i=0; i<n; i++) if(s1[i]=='-') s1[i] = '(';
        }
        else{
            for(int i=0; i<n; i++) if(s1[i]=='-') s1[i] = ')';
        }

        if(isBalancedExp(s1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}