#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){ 
        int a,b,c;
        cin >> a >> b>> c;
        int hcf = __gcd(a,b);
        if(c % hcf == 0)
            cout<<"Case "<<i<<": Yes"<<'\n';
        else
            cout<<"Case "<<i<<": No"<<'\n';
    }
}