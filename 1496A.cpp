#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>k>>s; 
        bool flag = true;
        for(int i = 0 ; i < k ; ++i)
		    flag = flag && s[i] == s[n - i - 1];
	    cout<<(flag && k * 2 < n ? "YES\n" : "NO\n");
    }
}