#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n = 5;
    map<int, int> mp;
    while(n--){
        int x;
        cin>>x;
        mp[x]++;
    }

    int three = 0, two = 0;
    for(auto it = mp.begin(); it!=mp.end(); it++) {
        if(it->second == 3) three++;
        else if(it->second == 2) two++;
    }

    if(three == 1 && two == 1) cout<<"Yes\n";
    else cout<<"No\n";
    
    return 0;
}