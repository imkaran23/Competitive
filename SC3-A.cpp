#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;

    int lo = 0, hi = (a*c)/b , mid;
    while(lo<hi){
        mid = lo + (hi-lo)/2;
        int ans = mid + b*c;
        if((mid + c)*b >= a*c) hi = mid;
        else lo = mid + 1;
    }

    cout<<hi<<"\n";
    return 0;
}