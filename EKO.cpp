#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int bsearch(int a[],int n,int k){
    int lo, hi, mid, i;
    long long int count;
    lo = 1, hi = a[n-1];

    while(lo < hi) {
        mid = lo + (hi-lo+1)/2;
        count = 0;
        for(i = 0; i < n; i++) {
            if(a[i] > mid) {
                count = count + (a[i]-mid);
            }
        }

        if(count >= k) lo = mid;
        else hi = mid-1;
    }
    return lo;
}
int main(){
    long long int k;
    int n,t,i,ans;
    cin>>n>>k;
    for(i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
    cout<<bsearch(a,n,k)<<"\n";
    return 0;
}