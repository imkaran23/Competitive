#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n,k;
        cin>>n>>k;
        int a[n];
        for (int i = 0; i < n; i++) cin>>a[i];

        if(k>10000) cout<<-1<<"\n";
        else
        {
            int i,j;
            for (j = 0; j < k; j++){
                for (i = 0; i+1 < n; i++){
                    if(a[i]<a[i+1]){
                        a[i]++;
                        break;
                    }
                }
            }

            if(i+1==n) cout<<-1<<"\n";
            else cout<<i+1<<"\n";
        }
    }
}