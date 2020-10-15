#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(true){
        cin>>n;
        if(!n) break;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(), a.end());

        int ans = 0;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                long x = a[i] + a[j]  + 1;
                int y = lower_bound(a.begin()+j+1, a.end(),x) - a.begin();
                ans += n-y;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}