#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = true;
        for(int i=0; i<=n/3; i++){
            x = n - 3*i;
            for(int j=0; j<=x/5; j++){
                y = x-5*j;
                if(y%7==0){ cout<<i<<" "<<j<<" "<<y/7<<endl; flag = false; break;}
            }
            if(!flag) break;
        }
        if(flag) cout<<-1<<endl;
    }
    return 0;
}