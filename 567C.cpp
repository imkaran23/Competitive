#include <iostream>
#include <unordered_map>
#define MAXN 200005

using namespace std;
typedef long long ll;

ll N, K, a[MAXN], ans;
unordered_map < ll, ll > L, R;

int main ()
{
	cin >> N >> K;
	for ( ll i = 0; i < N; i++ )
		cin >> a[i], R[a[i]]++;

	for ( ll i = 0; i < N; i++ )
	{
		R[a[i]]--;
		if ( a[i] % K == 0 )
			ans += L[a[i] / K] * R[a[i] * K];
		L[a[i]]++;
	}
	cout << ans << "\n";
	return 0;
}

