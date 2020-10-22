#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a, long long val){
    int n = a.size();
	for (long long i = 0; i < n; ++i){
		if(a[i]-n*val-i<=0)
			return true;
	}
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    long long l = 0, r = 1e9+1;
    while(l<=r){
    	long long mid = (l+r)/2;
    	if(check(a,mid)) r = mid - 1;
    	else l = mid + 1;
    }

    long long ans = r+1;
    for (long long i = 0; i < n; ++i){
    	if(a[i]-n*ans-i<=0){
    		cout<<i+1;
    		return 0;
    	}
    }
    return 0;
}