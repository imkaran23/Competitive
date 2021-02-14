#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int a,b,ans=INT_MAX;
        cin>>a>>b;

        for(int i=max(b,2); i<=b+32; i++){
			int A=a,z=0;
			while(A){
				A/=i;
                z++;
			}
			ans=min(ans,z+i-b);
		}
        cout<<ans<<"\n";
    }
}