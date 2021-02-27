#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n, ans = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin>>a[i];
        for (int i = 0; i < n-1; i++){
            int x = min(a[i], a[i+1]);
            int y = max(a[i], a[i+1]);
            if(2*x>=y) continue;
            else {
                while(2*x<y){
                    ans++;
                    x*=2;
                }
            }
        }
        cout << ans << "\n";
    }
}