#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        double n,m,x;
        cin >> n;
        m = cbrt(n);

        bool flag = false;
        for (long long int i = 1; i <= m; i++) {
            x = cbrt(n-i*i*i);
            if(x>0 && floor(x)==x){
                flag = true;
                break;
            }
        }

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}