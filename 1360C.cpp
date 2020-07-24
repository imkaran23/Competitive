#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll a[n];
		ll odd = 0;
		for(int i=0;i<n;++i){
			cin>>a[i];
			if(a[i]%2==1) odd++;
		}
		sort(a,a+n);
		bool b =  0;
		for(int i=0;i<n-1;++i){ 
			if(a[i]+1==a[i+1]) b=1;
		}
		if(odd %2==0 || b) {cout<<"YES\n";}
		else cout<<"NO\n";
 
	}
}