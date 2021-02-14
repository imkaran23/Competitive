#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){ 
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;

        int u=0,d=0,l=0,r=0;
        for(char c: s){
            if(c=='U') u++;
            if(c=='D') d++;
            if(c=='L') l++;
            if(c=='R') r++;
        }

        bool f1=false, f2=false;
        if(x>=0&&r>=x || x<=0&&l>=abs(x)) f1=true;
        if(y>=0&&u>=y || y<=0&&d>=abs(y)) f2=true;

        if(f1&&f2) cout<<"YES\n";
        else cout<<"NO\n";
    }
}