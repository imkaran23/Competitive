#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,moves=0;
        cin>>n;

        while(true){
            if(n%6==0){
                n/=6;
                moves++;
            }
            else if(n*2%6==0){
                n = (n*2)/6;
                moves+=2;
            }
            else break;
        }

        if(n==1) cout<<moves<<endl;
        else cout<<-1<<endl;
    }
}