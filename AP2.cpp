#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, c;
	long long a, b, d, x;
	scanf("%d",&t);
	while (t--){
		scanf("%lld %lld %lld", &a, &b, &d);
		n = (d / (double)(a + b)) * 2;
		c = (b - a) / (n - 5);
		x = a - (c << 1);

		printf("%d\n%lld",n, x);
		for (int i = 1; i < n; ++i){
			printf(" %lld", x+=c);
		}
		printf("\n");
	}

	return 0;
}

// int main()
// {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
//     long long t,x,y,s,n,d,a;
//     cin>>t;
//     while(t--){ 
//         cin>>x>>y>>s;
//         n = (2*s)/(double)(x+y);
//         d = (y-x)/(n-5);
//         a = x-2*d;
//         for (int i = 0; i < n; ++i) cout<<a+i*d<<" ";
//         cout<<"\n";
//     }
//     return 0;
// }