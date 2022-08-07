#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        int n, x, y;
        cin>>n;

        int xmax = 0, xmin = 0, ymax = 0, ymin = 0;

        while(n--){
            cin>>x>>y;
            xmax = max(xmax, x);
            xmin = min(xmin, x);
            ymax = max(ymax, y);
            ymin = min(ymin, y);
        }

        cout << 2 * (xmax + ymax + abs(xmin) + abs(ymin)) << '\n';
        
    }

    return 0;
}