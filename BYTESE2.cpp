#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n, x, y, ans=INT_MIN, tmp=0;
        cin >> n;
        vector<pair<int,int>> a(2*n);
        for (int i = 0; i < 2*n; i+=2) {
            cin>>x>>y; 
            a[i] = {x,'e'};
            a[i+1] = {y,'x'};
        }
        sort(a.begin(),a.end());

        for (int i = 0; i < 2*n; i++) {
            if(a[i].second=='e') tmp++;
            else tmp--;
            ans = max(ans,tmp);
        }

        cout<<ans<<"\n";
    }
}