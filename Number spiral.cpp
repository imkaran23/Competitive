#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    long long int t,x,y;
 
    cin>>t;
 
    while(t--){
        cin>>x>>y;
 
        long long int n = max(x,y);
 
        long long int ans = 1 + n*(n-1);
 
        if(n==x){
            if(x%2){
                while(n!=y){
                    n--;
                    ans--;
                }
            }
            else{
                while(n!=y){
                    n--;
                    ans++;
                }
            }
        }
        else{
            if(y%2){
                while(n!=x){
                    n--;
                    ans++;
                }
            }
            else{
                while(n!=x){
                    n--;
                    ans--;
                }
            }
        }
 
        cout<<ans<<"\n";
    }
 
    return 0;
}
