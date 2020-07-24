#include <iostream>
using namespace std;
int main()
{
	int t;
    cin>>t;
    while(t--)
	{
		int n,k,t=0;
        cin>>n>>k;
        int d=k;
        string s;
        cin>>s;
		for(int i=0;i<s.size();i++)
		{
            if(s[i]=='0') d++;
            else{d-=k; t+=d/(k+1); d=0;}
		}
		cout<<t+d/(k+1)<<endl;
	}
	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,k,l0=0,t0=0,m0=0,ans=0;
//         bool flag = true;
//         cin>>n>>k;
//         string s;
//         cin>>s;
        
//         f(i,0,s.size()-1){
//             if(flag && s[i]=='0') l0++;
//             else if(s[i]=='1') {flag = false; ans += m0/(2*k+1); m0=0; t0=0;}
//             else {m0++; t0++;}
//             // cout<<l0<<" "<<m0<<" "<<t0<<" "<<ans<<endl;
//         }

//         if(l0>0 && m0==0 && t0==0 && k>=l0) {cout<<1<<endl; continue;}

//         ans += l0/(k+1) + t0/(k+1);

//         cout<<ans<<endl;
//    }
//     return 0;
// }