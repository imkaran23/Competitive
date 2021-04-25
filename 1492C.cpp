#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    string a,b;
    cin>>n>>m>>a>>b;
    vector<int> v1,v2;

    int i=0;
    for(int j=0; j<n; j++){
        if(a[j]==b[i]) {
            v1.push_back(j);
            i++;
        }
        if(i==m) break;
    }

    i=m-1;
    for(int j=n-1; j>=0; j--){
        if(b[i]==a[j]) {
            v2.push_back(j);
            i--;
        }
        if(i==-1) break;
    }

    reverse(v2.begin(),v2.end());
    int ans = INT_MIN;
    for(int j=0; j<m-1; j++) ans = max(ans, v2[j+1]-v1[j] );
    cout<<ans<<"\n";
}