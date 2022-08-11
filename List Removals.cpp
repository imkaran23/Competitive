#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;

    rope<int> r;
    for(int i=0; i<n; i++) {
        int t;
        cin>>t;
        r.push_back(t);
    }

   for(int i=0; i<n; i++) {
        int q;
        cin>>q;
        q--;
        cout<<r[q]<<' ';
        r.erase(r.mutable_begin()+q);
    }

    return 0;
}