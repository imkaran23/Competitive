#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& a ,int& n){
	for(int i=1; i<n; i++) if(a[i]>a[i+1]) return 0;
	return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,n;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> a(n+1,0);
        for (int i=1; i<=n; i++) cin >> a[i]; 
        int ans = 0;   
        for(int i=1; i<=n; i++){
            if(check(a,n)) break;
            if(a[i]>x) ans++,swap(x,a[i]);
        }

        if(check(a,n)) cout<<ans<<"\n";
        else cout<<-1<<"\n";
    }
    return 0;
}
