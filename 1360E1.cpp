#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n][n];
        for(int i=0; i<n; i++){ 
            cin>>s;
            for(int j=0; j<n; j++) 
                a[i][j] = s[j];
        }

        bool f1, f2, ans=true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                f1=true; f2=true;
                if(a[i][j]=='1'){
                    if(j+1<n && a[i][j+1]=='0') f1 = false;
                    if(i+1<n && a[i+1][j]=='0') f2 = false;
                }

                if(f1==false && f2==false) {ans = false; break;}
            }
            if(!ans) break;
        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}