<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
#define ii pair<long long, long long>
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m,a,b,c,q;

    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1,INT64_MAX));
    vector<long long> vis(n+1,0);

    while(m--){
        cin>>a>>b>>c;
        dist[b][b] = 0;
        dist[a][a] = 0;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

   for(int k = 1; k<=n; k++){
       for(int i=1; i<=n; i++){
           for(int j=1; j<=n; j++){
               if(dist[i][j] > dist[i][k] + dist[k][j] &&
                    (dist[i][k]!=INT64_MAX && dist[k][j]!=INT64_MAX))

                    dist[i][j] = dist[i][k] + dist[k][j];
           }
       }
   }

   while (q--){
       cin>>a>>b;
       if(dist[a][b]==INT64_MAX) cout<<-1<<'\n';
       else cout<<dist[a][b]<<'\n';
   }
    
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;
#define ii pair<long long, long long>
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m,a,b,c,q;

    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1,INT64_MAX));
    vector<long long> vis(n+1,0);

    while(m--){
        cin>>a>>b>>c;
        dist[b][b] = 0;
        dist[a][a] = 0;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

   for(int k = 1; k<=n; k++){
       for(int i=1; i<=n; i++){
           for(int j=1; j<=n; j++){
               if(dist[i][j] > dist[i][k] + dist[k][j] &&
                    (dist[i][k]!=INT64_MAX && dist[k][j]!=INT64_MAX))

                    dist[i][j] = dist[i][k] + dist[k][j];
           }
       }
   }

   while (q--){
       cin>>a>>b;
       if(dist[a][b]==INT64_MAX) cout<<-1<<'\n';
       else cout<<dist[a][b]<<'\n';
   }
    
    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}