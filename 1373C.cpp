#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        string s;
        cin>>s;
        long long int x=0,a=0;
        for(int i=0;i<s.length();i++){ 
            if(s[i]=='+') a++;
            else{
                a--;
                if(a<0) x+=i+1,a=0;
            }
        }
        cout<<x+s.size()<<endl;
    }
}