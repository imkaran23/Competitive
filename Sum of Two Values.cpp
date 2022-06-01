#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    } 

    map<int,int> mp;

    for(int i=0; i<n; i++){
        if(x-a[i]<0)
            continue;
        if(mp.find(x-a[i])!=mp.end()){
            cout<<mp[x-a[i]]<<" "<<i+1;
            return 0;
        }
        mp[a[i]] = i+1;
    }

    cout<<"IMPOSSIBLE";

    return 0; 
}