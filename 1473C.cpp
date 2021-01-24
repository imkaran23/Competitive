#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<k-(n-k);i++)cout<<i<<" ";
		for(int i=k;i>=2*k-n;i--)cout<<i<<" ";
		cout<<"\n";
    }
    return 0;
    
}
