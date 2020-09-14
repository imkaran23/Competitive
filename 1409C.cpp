#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        int z=1,k;
        for(int i=1; i<=y-x; i++){
            if(y-(n-1)*i<=x && (y-x)%i==0){ k=i; break;}
        }

        for(int j=0; j<n; j++){
            if(y-j*k >0) cout<<y-j*k<<" ";
            else {cout<<y+z*k<<" "; z++;}
        }
        cout<<endl;
    } 
    return 0;
}