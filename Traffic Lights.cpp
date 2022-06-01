#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>x>>n;

    int a[n];

    set<int> s;
    multiset<int> d;
    s.insert(0);
    s.insert(x);
    d.insert(x);

    for(int i=0; i<n; i++){
        cin>>a[i];
        auto it = s.lower_bound(a[i]);
        it--;
        auto l = *it; 
        auto u = *(s.upper_bound(a[i]));

        s.insert(a[i]);

        d.erase(d.find(u-l));
        d.insert(a[i]-l);
        d.insert(u-a[i]);

        // cout<<l<<' '<<u<<'\n';

        // for(auto itr=d.begin(); itr!=d.end(); itr++)
        //     cout<<*itr<<' ';
        // cout<<'\n';
        
        cout<<*(d.rbegin())<<' ';
    }

    return 0;
}