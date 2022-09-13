#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> a, b;

bool check(long long r){
    int i=0, j=0;
    while(i<n && j<m){
        if(a[i]>=b[j]-r && a[i]<=b[j]+r) i++;
        else j++;
    }
    if(i==n) return true;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    T = 1;
    // cin>>t;

    while(T--){
        cin>>n;
        string s;
        cin>>s;

        
    }

    return 0;
}