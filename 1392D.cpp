#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        int n,ans=0,l,flag=0;
        string s;
        cin>>n>>s;
        i=0;
        if(s[0]==s[n-1]) while(i<n&&s[i]==s[0]) i++;
        if(i==n) {
            cout<<long(ceil(n/3.0))<<endl;
            continue;
        }
        while(i<n){
            l=1;
            while(s[i%n]==s[(i+1)%n])
            {
                l++,i++;
                if(i>n-1) flag=1;
            }
            ans+=l/3;
            if(flag) break;
            i++;
        }
        cout<<ans<<endl;
    }
}
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n;
//     string s;
//     cin>>t;
//     while(t--){
//         cin>>n>>s;
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             int k = i-1<0?i-1+n:i-1;
//             int l = i-2<0?i-2+n:i-2;
//             if(s[i] == s[k] && s[i] == s[(i+1)%n] && s[i] == s[(i+2)%n]){
//                 ans++;
//                 if(s[i]=='L') s[i+1] = 'R';
//                 else s[i+1] = 'L';
//             }
//             else if((s[i] == s[k] && s[i] == s[(i+1)%n] && s[i] != s[(i+2)%n])){
//                 ans++;
//                 if(s[i]=='L') s[i] = 'R';
//                 else s[i] = 'L';
//             }
//             else if(s[i] == s[k] && s[i] == s[(i+1)%n] && s[i] == s[l]){
//                 ans++;
//                 if(s[i]=='L') s[i-1] = 'R';
//                 else s[i-1] = 'L';
//             }
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }