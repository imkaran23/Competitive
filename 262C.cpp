#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> temp;

void recur(int start, int l){
    if(l == 0){
        for(auto x : temp) cout<<x<<' ';
        cout<<'\n';
        return;
    }

    int r = m-l+1;

    for(int i = start; i<=r; i++){
        temp.push_back(i);
        recur(i+1, l-1);
        temp.pop_back();
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>m;

    recur(1, n);

    return 0;
}