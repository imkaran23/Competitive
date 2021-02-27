#include <bits/stdc++.h>
using namespace std;

// int recur(int n)
// {
// 	if(n<3) return n;
// 	else {
// 		int a,b;
// 		a = b = 0;
// 		for(int i = sqrt(n) ; i>=2 ; i--){
// 			if(n%i == 0){
// 				a = i;
// 				b = n/i;
// 				break;
// 			}
// 		}
// 		if(a==0 && b==0) return 0;
// 		else return (recur(a)+recur(b));
// 	}
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;
//     cout << recur(n);

//     return 0;
// }

const int MAX = 100005;
int N,f[MAX];
vector<int> divisors[MAX];

int main() {
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        for (int j = i; j <= N; j += i) {
            divisors[j].push_back(i);
        }
    }
    for (int i = 3; i <= N; i ++) {
        if ((int)divisors[i].size() == 2) {
            f[i] = 0;
        }
        else {
            f[i] = INT_MAX;
            int best = INT_MAX, bestSum = INT_MAX;
            for (int j : divisors[i]) {
                if (j + i / j < bestSum) {
                    best = j;
                    bestSum = j + i /j;
                }
            }
            f[i] = f[best] + f[i / best];
        }
    }
    cout << f[N] << endl;
    
    return 0;
}