#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x;
    cin>>t;
    while(t--){
        cin>>x;
        int unit = x%10, count=0;
        while(x>0){
            count++;
            x/=10;
        }

        if(count==1) cout<<(unit-1)*10 + 1<<"\n";
        else if(count==2)cout<<(unit-1)*10 + 3<<"\n";
        else if(count==3)cout<<(unit-1)*10 + 6<<"\n";
        else cout<<(unit-1)*10 + 10<<"\n";
    }
    return 0;
}