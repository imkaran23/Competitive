#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		long long k=sqrt(n)+1, p=1, ans=1, l=n;
		
		for(long long i=2; i<k; i++){
			long long cont=0, q=n;
			while(q%i==0){
				q=q/i;
				cont++;
			}
			if(cont>ans)ans=cont,p=i,l=q;
		}
		cout << ans << endl;
		for(int i = 0; i < ans-1; i++) cout << p << " ";
		cout << l*p << endl;
	}
 
	return 0;
}