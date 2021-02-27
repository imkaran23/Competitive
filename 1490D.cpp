#include <bits/stdc++.h>
using namespace std;
int a[101], b[101];

void recur(int l, int r, int d){
    if(l>r) return;
    int m = INT_MIN, idx;
    for (int i = l; i <=r; i++) {
        if(a[i]>m) {
            m=a[i];
            idx=i;
        }
    }

    b[a[idx]] = d;
    recur(l, idx-1, d+1);
    recur(idx+1, r, d+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin>>a[i];
        recur(0,n-1,0);
        for (int i = 0; i < n; i++) cout << b[a[i]] << " ";
        cout<<"\n";
    }
}