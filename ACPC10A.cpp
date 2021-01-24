#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,a,b,c;
    while(cin >> a >> b >> c){
        if(a==0 && b==0 && c==0) break; 
        if(b-a == c-b) cout<<"AP "<<c+b-a<<"\n";
        else if(b/a==c/b) cout<<"GP "<<c*(b/a)<<"\n";
    }
    return 0; 
}
