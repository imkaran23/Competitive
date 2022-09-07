#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x[4], y[4];
    for(int i=0; i<4; i++) cin>>x[i]>>y[i];
    
    bool sign, ans = true;
    for(int i=0; i<4; i++){
        int dx1 = x[(i+1)%4] - x[i%4];
        int dx2 = x[(i+2)%4] - x[i%4];
        int dy1 = y[(i+1)%4] - y[i%4];
        int dy2 = y[(i+2)%4] - y[i%4];

        int zcrossproduct = dx1*dy2 - dx2*dy1;

        if(i==0) sign = zcrossproduct>0;
        else if(zcrossproduct>0 != sign) ans = false;
    }

    if(ans) cout<<"Yes\n";
    else cout<<"No\n";
    
    return 0;
}