#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int j=0;j<m;j++) cin>>b[j];
    
	for(int ans=0;ans<512;ans++){
		int cnt=0;
		for(int i=0;i<n;i++){
			bool fnd=false;
			for(int j=0;j<m;j++){
				if(((a[i]&b[j])|ans)==ans) fnd=true;
			}
			if(!fnd) break;
			cnt++;
		}
		if(cnt==n){
			cout<<ans<<"\n";
			return 0;
		}
	}
}
