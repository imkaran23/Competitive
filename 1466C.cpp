#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.size();
        int ans=0,i,k=65;
        for(i=0; i+2<n ; i++){
            if(s[i]==s[i+1] && s[i+1]==s[i+2]){ 
                ans+=2;
                s[i+1]=k;
                k++;
                s[i+2]=k;
                k++;
            }
            else if(s[i]==s[i+2] && s[i+1]!=s[i]){ 
                ans++;
                s[i+2]=k;
                k++;
            }
            else if(s[i+1]==s[i]){ 
                ans++;
                s[i+1]=k;
                k++;
            }
            else if(s[i+1]==s[i+2]){ 
                ans++;
                s[i+2]=k;
                k++;
            }
            if(k>90) k=65;
            // cout<<s<<" ";
        }

        if(i+1<n && s[i]==s[i+1]) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}