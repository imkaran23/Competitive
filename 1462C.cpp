#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n>45) cout<<-1<<"\n";
        else if (n<10) cout<<n<<"\n";
        else{
            int ans = 0,k=0;
            for(int i=9; i>0 ; i--){
                if(n-i>=0){
                    n-=i;
                    ans += i*(int)pow(10,k);
                    k++; 
                }
                if(n==0) break;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}