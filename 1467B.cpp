#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
int a[N], n;

int isValley(int i) {
    return (i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1]);
}

int isHill(int i) {
    return (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        int is[n] = {};
        long long s = 0;
        for (int i = 1; i < n - 1; i++) {
            if (isHill(i) || isValley(i))
                is[i] = 1, s++;
        }

        long long ans = s;
        for (int i = 1; i < n - 1; i++) {
            int temp = a[i];
            a[i] = a[i - 1];
            ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
            a[i] = a[i + 1];
            ans = min(ans, s - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
            a[i] = temp;
        }

        cout << ans << "\n";
    }
    return 0;  
}
