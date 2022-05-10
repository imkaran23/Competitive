#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,x,maxi=0;
        cin>>n;

        map<int,int> mp;
        for(int i=0; i<n; i++){
            cin>>x;
            mp[x]++;
            maxi = max(maxi, mp[x]);
        }

        if(n==1 || maxi==n)
            cout<<0<<"\n";
        else if(maxi>1)
            cout<<1 + (n-maxi)<<"\n";
        else
            cout<<-1<<"\n";
    }
    
    return 0;
}