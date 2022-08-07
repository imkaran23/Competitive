#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;

    char a[n][n];

    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            cin>>a[i][j];
        }
    }
    
    bool ans = true;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i][j] == 'W' && a[j][i] != 'L') ans = false;
            else if(a[i][j] == 'L' && a[j][i] != 'W') ans = false;
            else if(a[i][j] == 'D' && a[j][i] != 'D') ans = false;
        }
    }    

    if(ans) cout<<"correct\n";
    else cout<<"incorrect\n";

    return 0;
}