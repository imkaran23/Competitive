#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int t;
	cin>>t;
	while(t--)
	{
	int n,m;
	cin>>n>>m;
	int a[n+m]={},b[n+m]={};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			if(x) a[i+j]++;
			else b[i+j]++;
		}
	}
	int ans=0;
	for(int i=0,j=n+m-2;i<j;i++,j--)
	{
		ans+=min(a[i]+a[j],b[i]+b[j]);
	}
	cout<<ans<<endl;
}
}