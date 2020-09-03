#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,p,f,c1,c2,s,w;
    cin>>t;
    while(t--){
        cin>>p>>f>>c1>>c2>>s>>w;
        if(s>w){
			swap(s,w);
			swap(c1,c2);
		}
        int ans=0;
		for(int i=0;i<=min(c1,p/s);i++){
			int w1=min(c2,(p-i*s)/w);
			int s2=min(c1-i,f/s);
			int w2=min(c2-w1,(f-s2*s)/w);
			ans= max(ans,i+w1+s2+w2);
		}
        cout<<ans<<endl;
    }
    return 0;
}