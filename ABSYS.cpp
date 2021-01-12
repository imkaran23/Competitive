#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    getline(cin, s);
    int plus, equal, machula;
    while(t--){
        getline(cin, s);
		getline(cin, s);
		plus = s.find("+");
		equal = s.find("=");
		machula = s.find("machula");
		int len = s.length();
		if(machula < plus)
			cout<<to_string(stoi(s.substr(equal + 1, len)) - stoi(s.substr(plus + 1, equal - 1)))<<s.substr(plus - 1, len)<<endl;
		else if(machula < equal)
			cout<<s.substr(0, plus + 2)<<to_string(stoi(s.substr(equal + 1, len)) - stoi(s.substr(0, plus - 1)))<<s.substr(equal - 1, len-1)<<endl;
		else 
			cout<<s.substr(0, equal + 2)<<to_string(stoi(s.substr(0, plus - 1)) + stoi(s.substr(plus + 1, equal - 1)))<<endl;
	}
    return 0;
}
