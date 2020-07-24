#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,y,ans;
    cin>>t;
    while(t--){
        cin>>n>>x;
        ans=0;
        vector<int> v;

        for(int i=0; i<n; i++){
            cin>>y;
            if(y>=x) ans++;
            else v.push_back(y);
        }

        sort(v.begin(),v.end(),greater<int>());

        int count=1;
        for(int i=0; i<v.size(); i++){
            if(v[i]*count>=x) {ans++; count=1;}
            else count++;
        }

        cout<<ans<<endl;
    }
}