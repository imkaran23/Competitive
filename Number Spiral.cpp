#include <bits/stdc++.h>
using namespace std;
const long long int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int x,y;
        cin>>x>>y;

        if(x>=y){
            int z = x*(x-1) + 1; 
            int y1 = x;
            if(x%2){
                z-=(y1-y);
            }
            else{
                z+=(y1-y);
            }

            cout<<z<<"\n";
        }

        else{
            int z = y*(y-1) + 1;
            int x1 = y;
            if(y%2){
                z+=(x1-x);
            }
            else{
                z-=(x1-x);
            }

            cout<<z<<"\n";
        }
    }

    return 0;
}