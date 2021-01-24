#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,m,x,i,j;
    cin>>t;
    while(t--){
        cin >> n;
        int a[n];
        for(i=0; i<n; i++) cin>>a[i];

        cin >> m;
        int b[m];
        for(i=0; i<m; i++) cin>>b[i];

        // sort(b,b+m);
        // int ans = INT_MAX;
        // for(i=0; i<n; i++){
        //     if((find(b,b+m,a[i])-b)!=m){
        //         ans = 0;
        //         break;
        //     }
        //     x = upper_bound(b,b+m,a[i]) - b;
        //     ans = min(ans,abs(b[x]-a[i]));
        //     x = lower_bound(b,b+m,a[i]) - b;
        //     ans = min(ans,abs(b[x]-a[i]));
        // }

        sort(a,a+n);
		sort(b,b+m);
		i=j=0;
		int ans = INT_MAX;
		while(i<n && j<m)
		{
			if(a[i]>b[j])
			{
				if(a[i]-b[j]<ans)
					ans=a[i]-b[j];
				j++;
			}
			else
			{
				if(b[j]-a[i]<ans)
					ans=b[j]-a[i];
				i++;	
			}
		}
        cout<<ans<<"\n";
    }
    return 0;
    
}
