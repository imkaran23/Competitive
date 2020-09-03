#include <bits/stdc++.h>
using namespace std;
int vis[102][102];
int n,m,x,y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin>>n>>m>>x>>y;
    int count = 0,a,b;
    while(count!=n*m){
        for(int j=y; j>=1; j--) { 
            if(!vis[x][j]) {cout<<x<<" "<<j<<endl; count++; b=j; vis[x][j]=1;}
        }
        for(int j=y+1; j<=m; j++) { 
            if(!vis[x][j]) {cout<<x<<" "<<j<<endl; count++; b=j; vis[x][j]=1;}
        }
        y = b;
        for(int i=x; i>=1; i--) { 
            if(!vis[i][y]) {cout<<i<<" "<<y<<endl; count++; a=i; vis[i][y]=1;}
        }
        for(int i=x+1; i<=n; i++) { 
            if(!vis[i][y]) {cout<<i<<" "<<y<<endl; count++; a=i; vis[i][y]=1;}
        }
        x = a;
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	int n,m,x,y;
// 	cin>>n>>m>>x>>y;
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<m;j++)
// 		{
// 			cout<<x<<" "<<y<<endl;
// 			if(j!=m-1)
// 			    y=y%m +1;
// 		}
// 		x=x%n +1;
// 	}
	
// }