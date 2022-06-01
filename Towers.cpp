#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    multiset<int> s;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s.upper_bound(a[i])==s.end()){
            ans++;
        }
        else{
            s.erase(s.upper_bound(a[i]));
        }
        s.insert(a[i]);
    }

    cout<<ans<<'\n';

    return 0;
}