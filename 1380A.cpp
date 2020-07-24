#include<iostream>
using namespace std;
 
int q, n, a[1234];
int main() {
	scanf("%d", &q);
	while (q--) {
		bool bl = true;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)scanf("%d", a + i);
 
		for (int i = 1; bl&&i + 1 < n; ++i)
			if (a[i] > a[i + 1] && a[i] > a[i - 1])
				printf("YES\n%d %d %d\n", i, i + 1, i + 2), bl = false;
 
		if (bl)puts("NO");
	}
	return 0;
}