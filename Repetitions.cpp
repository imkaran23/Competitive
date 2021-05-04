#include <bits/stdc++.h>
using namespace std;
const long long int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    int ans=1, tmp=1;
    for(int i=1; i<s.size(); i++){
        if(s[i]==s[i-1]){
            tmp++;
        }
        else{
            tmp=1;
        }

        ans = max(ans,tmp);
    }
    cout<<ans<<"\n";

    return 0;
}