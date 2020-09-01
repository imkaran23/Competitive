// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int t,n;
//     string s;
//     cin>>t;
//     while(t--){
//         cin>>n>>s;
//         int a[n+1];
//         a[0] = 0;
//         for(int i=1;i<n+1;i++) a[i] = a[i-1] + s[i-1] - '0';
//         // for(int i=0;i<n+1;i++) cout<<a[i];

//         int ans = 0;
//         for(int i=1;i<n+1;i++){
//             if(a[i]-a[i-1]==1) ans++;
//             for(int j=i+1;j<n+1;j++){
//                 if(j-i+1==a[j]-a[i-1]) ans++;
//             }
//         }

//         cout<<ans<<endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;int T,n;
string s;
unordered_map<int,int>mp;
int main(){
	cin>>T;
	while(T--){
        mp.clear(); 
		cin>>n>>s;
        mp[0]++;
		long long ans=0,sum=0;
		for(int i=0;i<n;i++){
			sum+=s[i]-'1'; 
			ans+=mp[sum];
            mp[sum]++;
		}
		cout<<ans<<endl;
	}
}