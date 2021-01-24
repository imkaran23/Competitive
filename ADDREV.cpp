#include <bits/stdc++.h>
using namespace std;

int rev(int x){
    int y = 0;
    while(x>0){
        y = 10*y + x%10; 
        x/=10;
    }
    return y;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<rev(rev(a) + rev(b))<<"\n";
    }
    return 0; 
}
