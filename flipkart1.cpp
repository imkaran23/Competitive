// Given n groups of singers (as array of size n with arr[i] denoting the ith group size) and m microphones available, we had to output the minimum largest group size sharing a single mic.

// A group could only be divided into two further groups at a time (i.e, in a single division, only two subgroups could be formed. Further these subgroups could also be divided using the same approach).
 
// input : [100, 60, 80, 40, 30], m = 9
// output : 40
// explanation : groups after division could be as follows [40,40,20,40,20,40,40,40,30]

#include <bits/stdc++.h>
using namespace std;

int mic(vector<int>& a,int x){
    int ans = 0;
    for(int i=0; i<a.size(); i++) ans += a[i]/x + (a[i]%x?1:0) ;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m; // Assume m>=n
    vector<int> a(n);
    for(int i; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    int lo = a[0], hi = a[n-1];

    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        int curr_m = mic(a,mid);
        // cout<<curr_m<<" "<<m<<" "<<mid<<"\n";
        if(curr_m>m) lo = mid+1;
        else hi = mid;
    }

    cout<<hi<<"\n";
    return 0;
}