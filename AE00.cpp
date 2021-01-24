#include <bits/stdc++.h>
using namespace std;

int factors(int x){
    int f=0;
    for(int i = 1; i<=x; i++){
        if(i*i==x) 
            f+=2;
        else if(x%i==0)
            f++;
    }
    return f/2;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n,t=1;
    while(t--){
        cin>>n;
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans += factors(i);
        }

        cout<<ans<<"\n";
    }
    return 0; 
}
