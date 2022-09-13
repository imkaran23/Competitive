#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int T;
    T = 1;
    // cin>>t;

    while(T--){
        int n, t;
        cin>>n>>t;

        vector<int> v(n);
        for(int i=0; i<n ;i++) cin>>v[i];

        int l = 0, sum = 0, ans = 0;
        for(int i=0; i<n; i++){
            sum += v[i];
            if(sum<=t){
                ans = max(ans, i-l+1);
            }
            else{
                while(sum>t){
                    sum -= v[l];
                    l++;
                }
            }
        }

        cout<<ans<<'\n';
    }

    return 0;
}