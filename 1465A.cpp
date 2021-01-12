#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        int idx = n-1;
        while(idx >=0 && s[idx]==')') idx--;
        int a = idx+1, b = n-idx-1;
        if(b>a) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}