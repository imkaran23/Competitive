#include<iostream>
using namespace std;
int main() {
	int q;
	cin>>q;
	while (q--) {
		long long a,b;
		cin>>a>>b;
		if (a>b) swap(a,b);
		int i=0;
		while (a<b) {
			a*=2;
			i++;
		}
    if (a!=b) cout<<-1<<endl;
    else cout<<i/3+min(1,i%3)<<endl;
	}
}
