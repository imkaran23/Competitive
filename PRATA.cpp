#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& a,int t){
    int ans = 0;
    for(int i=0; i<a.size(); i++){
        ans += (int)(-0.5 + sqrt( 0.25 + 2*( (double)t/a[i] ) ) );
        // int time = 0, j = 1;
        // while(1){
        //     time += j*a[i];
        //     j++;
        //     if(time > t) break;
        //     ans++;
        // }
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,l,p;
    cin>>t;
    while(t--){
        cin>>p>>l;
        vector<int> a(l);
        for(int i=0; i<l; i++) cin>>a[i];
        sort(a.begin(), a.end());

        int lo = 1, hi = 4004000 , mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            int ans = check(a,mid);
            if(ans < p) lo = mid + 1;
            else hi = mid;
        }

        cout<<lo<<"\n";
    }
    return 0;
}