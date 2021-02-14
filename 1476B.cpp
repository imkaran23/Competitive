#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){ 
        long long int n, k , i, ans = 0, count = 0;
        cin>>n>>k;
	    vector<long long int> vecs(n),vect;
	    for(i=0;i<n;i++)
	    {
	        cin>>vecs[i];
	        count+=vecs[i];
	        vect.push_back(count);
	    }
	    for(i=1;i<n;i++)
	    {
	        if(vect[i-1]+ans<=(vecs[i]*100)/k)
	        {
	            
	            ans+=(vecs[i]*100)/k-vect[i-1]-ans;
	            if((vecs[i]*100)%k!=0)
	            ans++;
	        }
	    }
	    cout<<ans<<"\n";
    }
}