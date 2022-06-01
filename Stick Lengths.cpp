#include<bits/stdc++.h>
using namespace std;

long long int solve(int a[], int n, int x){
    long long int ans = 0;
    for(int i=0; i<n; i++)
        ans += abs((long long)a[i]-(long long)x);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    sort(a, a+n);

    cout<< min(solve(a,n,a[n/2]), solve(a,n,a[(n-1)/2]));

    return 0;
}