#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<abs(a-b)/10 + ((a-b)%10==0?0:1)<<endl;
    }
    return 0;
}