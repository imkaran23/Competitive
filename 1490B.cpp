#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n, x, ans = 0;
        cin >> n;
        int a[3];
        a[0] = a[1] = a[2] = 0;
        for (int i = 0; i < n; i++) {cin>>x; a[x%3]++;}

        int c = n/3, i=0;
        while (true){
            if(a[i]==c && a[(i+1)%3]==c && a[(i+2)%3]==c) break;
            while(a[i]>c){
                ans++;
                a[i]--;
                a[(i+1)%3]++;
            }
            // cout<<i<<" "<<a[i]<<" "<<a[(i+1)%3]<<" "<<ans<<"\n";
            i++;
            i%=3;
        }
        cout << ans << "\n";
    }
}