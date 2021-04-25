#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n,u,d,l,r,r1=0,l1=0,u1=0,d1=0;
        cin>>n>>u>>r>>d>>l;

        if(u==n && d==n ) r1+=2,l1+=2; 
        else if(u==n-1 && d==n-1) r1++,l1++;
        else if( (u==n || d==n) && (u==n-1 || d==n-1)){
            if(r<l) l1+=2,r1++;
            else l1++,r1+=2;
        }
        else if(u==n || d==n) r1++,l1++;
        else if( u==n-1 || d==n-1){
            if(r<l) l1++;
            else r1++;
        }

        if(r==n && l==n ) u1+=2,d1+=2; 
        else if(r==n-1 && l==n-1) u1++,d1++;
        else if( (r==n || l==n) && (r==n-1 || l==n-1)){
            if(u<d) d1+=2,u1++;
            else d1++,u1+=2;
        }
        else if(r==n || l==n ) u1++,d1++;
        else if(r==n-1 || l==n-1){
            if(u<d) d1++;
            else u1++;
        }

        cout<<u1<<" "<<r1<<" "<<d1<<" "<<l1<<" ";

        if(r>=r1 && l>=l1 && u>=u1 && d>=d1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}