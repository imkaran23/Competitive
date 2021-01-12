#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        unordered_set<int> s;
        for(int i=0; i<n ; i++){
            cin>>a[i];
        }

        int ans = 0;
        for(int i=0; i<n ; i++){
            for(int j=i+1; j<n ; j++){
                int y = a[j]-a[i];
                if(s.find(y)==s.end()){
                    ans++;
                    s.insert(y);
                }
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}