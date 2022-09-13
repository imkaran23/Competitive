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
        cin>>n>>m;
        a.resize(n);
        b.resize(m);
        for(int i=0; i<n ;i++) cin>>a[i];
        for(int i=0; i<m ;i++) cin>>b[i];

        long long l = 0, h = INT_MAX, ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(mid)){
                ans = mid;
                h = mid-1;
            }
            else 
                l = mid+1;
        }

        cout<<ans;
    }

    return 0;
}