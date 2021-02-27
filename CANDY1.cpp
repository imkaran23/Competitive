#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n && n!=-1){ 
        int a[n];
        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {cin>>a[i]; sum+=a[i];}
        if(sum>0 && sum%n==0){
            sum/=n;
            for (int i = 0; i < n; i++) ans += abs(sum-a[i]);
            cout<<ans/2<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
}