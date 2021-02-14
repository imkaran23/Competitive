#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int a[m],b[n];
        for(int i=0; i<m; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        sort(a,a+m);
        sort(b,b+n);
        int i=0, j=0;
        while(i<m && j<n){
            if(a[i]<b[j]) i++;
            else j++;
        }

        if(i==m && j==n) cout<<"uncertain\n";
        else if(i<m) cout<<"Godzilla\n";
        else cout<<"MechaGodzilla\n";
    }
    return 0;
}