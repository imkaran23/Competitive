#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n,ans=0,x;
        cin>>n;
        int a[n];
        vector<int> v(101,0);
        for(int i=0; i<n; i++){
			cin>>a[i];
            v[a[i]]++;
		}

        bool flag = false;
        for(int i=0; i<101; i++){
            if(v[i]){
                if(flag) ans+=v[i];
                else flag = true;
            }
        }
        cout<<ans<<"\n";
    }
}