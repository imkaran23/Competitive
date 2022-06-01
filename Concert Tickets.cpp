#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,x;
    cin>>n>>m;

    // multiset<int> s;
    multiset<int, greater<int>> s;

    for(int i=0; i<n; i++){
        cin>>x;
        // s.insert(-x);
        s.insert(x);
    } 

    for(int i=0; i<m; i++){
        cin>>x;
        // auto it  = s.lower_bound(-x);
        auto it  = s.lower_bound(x);
        if(it==s.end()) cout<<-1<<"\n";
        else{
            // cout<<-(*it)<<"\n";
            cout<<(*it)<<"\n";
            s.erase(it);
        }
    }

    return 0;
}