#include<bits/stdc++.h>
using namespace std;
int a[210]={},b[210]={},c[210]={},dp[210][210][210];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int x,y,z;
	cin>>x>>y>>z;
	for(int i=1;i<=x;i++) cin>>a[i];
    for(int i=1;i<=y;i++) cin>>b[i];
	for(int i=1;i<=z;i++) cin>>c[i];
    sort(a+1,a+x+1);
	sort(b+1,b+y+1);
	sort(c+1,c+z+1);

	int ans=0;
	for(int i=x;i>=0;i--){
		for(int j=y;j>=0;j--){
			for(int k=z;k>=0;k--){
				dp[i][j][k]=max(dp[i+1][j+1][k]+a[i+1]*b[j+1],max(dp[i+1][j][k+1]+a[i+1]*c[k+1],max(dp[i][j+1][k+1]+b[j+1]*c[k+1],0)));
				ans=max(ans,dp[i][j][k]);
			}
		}
	}
    
	cout<<ans;
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int r,g,b,x;
//     cin>>r>>g>>b;
//     vector<int> vr(r),vg(g),vb(b);
//     while(r--){ cin>>x; vr.push_back(x);}
//     while(g--){ cin>>x; vg.push_back(x);}
//     while(b--){ cin>>x; vb.push_back(x);}
//     vr.push_back(0),vb.push_back(0),vg.push_back(0);
//     sort(vr.begin(),vr.end(),greater<>());
//     sort(vg.begin(),vg.end(),greater<>());
//     sort(vb.begin(),vb.end(),greater<>());

//     long long ans = 0,tmp;
//     int i=0,j=0,k=0;

//     while(true){
//         tmp = 0;
//         if(vr[i]>vg[j]){
//             if(vg[j]>vb[k]){
//                 tmp=vr[i]*vg[j];
//                 i++,j++;
//             } 
//             else{
//                 tmp=vr[i]*vb[k];
//                 i++,k++;
//             }
//         } 
//         else{
//             if(vr[i]>vb[k]){
//                 tmp=vr[i]*vg[j];
//                 i++,j++;
//             }
//             else{
//                 tmp=vb[k]*vg[j];
//                 k++,j++;
//             }
//         }
//         if(tmp) ans += tmp;
//         else break;
//     }

//     cout<<ans<<endl;
// }