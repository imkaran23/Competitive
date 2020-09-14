#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int t; cin>>t;
	for(int i=0;i<t;++i){
		int64_t a,b,x,y,n; cin>>a>>b>>x>>y>>n;
		int64_t c=min(a-x,n),d=min(n-c,b-y);
		int64_t u=(a-c)*(b-d);
		int64_t e=min(b-y,n),f=min(n-e,a-x);
		int64_t v=(a-f)*(b-e);
		cout<<min(u,v)<<"\n"s;
	}
}
