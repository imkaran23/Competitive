#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        if(n==2){
            cout<<-1<<"\n";
            continue;
        }
        int x = 1, y = 2; 

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(x<=n*n) {
                    cout<<x<<" ";
                    x+=2;
                }
                else {
                    cout<<y<<" ";
                    y+=2;
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}