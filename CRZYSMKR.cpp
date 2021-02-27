#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        long long int n;
        cin >> n;
        cout<< (11-((n%11)*8)%11)%11 << "\n";
    }
} 