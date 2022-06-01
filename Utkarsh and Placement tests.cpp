#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        char a[3];
        for(int i=0; i<3; i++) cin>>a[i];

        char x,y;
        cin>>x>>y;

        for(int i=0; i<3; i++){
            if(a[i]==x || a[i]==y){
                cout<<a[i]<<"\n";
                break;
            }
        }
    }
    
    return 0;
}