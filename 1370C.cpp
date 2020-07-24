#include<bits/stdc++.h>
using namespace std;

const int N = 50000;

bool check_prime(int n){
	for(int i = 2; i <= min(N, n/2 ); i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        bool lose = (n == 1);
		if(n > 2 && n % 2 == 0){
			if((n & (n - 1)) == 0)
				lose = 1;
			else if(n % 4 != 0 && check_prime(n / 2))
				lose = 1;
		}
		if(lose) cout<<"FastestFinger\n";
		else cout<<"Ashishgup\n";
	}
}