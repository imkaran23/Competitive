#include <bits/stdc++.h>
using namespace std;

const int maxn=100010;

int t,n,m,a[maxn],b[maxn],c[maxn],ans[maxn];
vector<int> v[maxn],w[maxn];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		for(int i=1;i<=m;i++) scanf("%d",&c[i]);

		for(int i=1;i<=n;i++) v[i].clear(),w[i].clear();
		for(int i=1;i<=m;i++) ans[i]=0;

		for(int i=1;i<=n;i++) if(a[i]!=b[i]) v[b[i]].push_back(i); else w[b[i]].push_back(i);

		for(int i=1;i<=m;i++)
		{
			if(!v[c[i]].empty())
			{
				ans[i]=v[c[i]].back();
				w[c[i]].push_back(v[c[i]].back());
				v[c[i]].pop_back();
			}
			else if(!w[c[i]].empty())
			{
				ans[i]=w[c[i]][0];
			}
		}

		int f=ans[m];
		for(int i=1;i<=n;i++) if(!v[i].empty()) f=0;

		if(f==0)
		{
			puts("NO");
			continue;
		}

		puts("YES");
		for(int i=1;i<=m;i++) printf("%d ",ans[i]==0?f:ans[i]);puts("");
	}
	
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){ 
//         int n,m,x;
//         cin>>n>>m;
//         int a[n],ac[n+1],b[n],bc[n+1],cc[n+1],c[m];
//         vector<int> ans;

//         memset(cc,0,sizeof(cc));
//         memset(bc,0,sizeof(bc));
//         memset(ac,0,sizeof(ac));

//         for (int i = 0; i < n; i++) {
//             cin>>a[i];
//             ac[a[i]]++;
//         }
//         for (int i = 0; i < n; i++) {
//             cin>>b[i];
//             bc[b[i]]++;
//         }
//         for (int i = 0; i < m; i++){
//             cin>>c[i];
//             cc[c[i]]++;
//         }

//         int k=-1;
//         for (int i = 0; i < n; i++){
//             if(c[m-1]==b[i]){
//                 k=i+1;
//                 break;
//             }
//         }

//         if(k==-1) cout<<"NO\n";
//         else{
            
//             for (int i = 0; i < m; i++){
//                 bool flag = true;
//                 for(int j=0; j<n; j++){
//                     if(a[j]!=b[j] && c[i]==b[j]){
//                         a[j] = b[j];
//                         ans.push_back(j+1);
//                         flag = false;
//                         break;
//                     }
//                 }

//                 if(flag) ans.push_back(k);
//             }

//             bool flag = true;
//             for(int j=0; j<n; j++){
//                 if(a[j]!=b[j]){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(!flag) cout<<"NO\n";
//             else{
//                 cout<<"YES\n";
//                 for(int x : ans) cout<<x<<" ";
//                 cout<<"\n";
//             }
            
//         } 
//     }
// }