/*HOLI - Holiday Accommodation
no tags 

Nowadays, people have many ways to save money on accommodation when they are on vacation. One of these ways is exchanging houses with other people.

Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city and use someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:

All the people should go to one of the other people's city.
Two of them never go to the same city, because they are not willing to share a house.
They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.

Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people.

Input
The first line of input contains one integer T (1 ≤ T ≤ 10), indicating the number of test cases.

Each test case contains several lines. The first line contains an integer N (2 ≤ N ≤ 105), representing the number of cities. Then the following N-1 lines each contains three integers X, Y, Z (1 ≤ X, Y ≤ N, 1 ≤ Z ≤ 106), means that there is a highway between city X and city Y, and length of that highway.

You can assume all the cities are connected and the highways are bi-directional.

Output
For each test case in the input, print one line: "Case #X: Y", where X is the test case number (starting with 1) and Y represents the largest total travel distance of all people.

Example
Input:
2
4
1 2 3
2 3 2
4 3 2
6
1 2 3
2 3 4
2 4 1
4 5 8
5 6 5

Output:
Case #1: 18
Case #2: 62
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define f(i,a,b) for(int i=int(a);i<=int(b);i++)
vector<vector<pair<int,int> > > v;
bool vis[100005],vis1[100005];
int maxi,last;

void dfs(int x,int l){
    vis[x]=true;
    if(l>maxi && !vis1[x]){
        maxi=l;
        last=x;
    }
    f(i,0,v[x].size()-1){
        int y=v[x][i].first;
        if(!vis[y]){
            dfs(y,l+v[x][i].second);
        }
    }
}

int main(){
    int t;
    cin>>t;
    f(k,1,t){
        int n,x,y,w;
        cin>>n;
        v.clear();
        v.resize(n+1);
        f(i,1,n-1){
            cin>>x>>y>>w;
            v[x].push_back(make_pair(y,w));
            v[y].push_back(make_pair(x,w));
        }
        int ans=0;
        
        memset(vis1,0,sizeof(vis1));
        f(i,1,n){
            maxi=0;
            if(!vis1[i]){
                memset(vis,0,sizeof(vis));
                dfs(i,0);
                vis1[i]=true;
                vis1[last]=true;
                cout<<maxi<<endl;
                ans+=2*maxi;
            }
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}
*/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}



vector<pll>adj[100005];

// ret will contain the total travel distance (travelled one-sidedly) by the visitors , 
// that's why at the end we are multiplying by 2 as people from both sides are crossing 
// a particular edge.
ll ret=0;
ll n;

ll dfs(ll par, ll u){
  ll ans=1;
  for(ll i=0;i<adj[u].size();i++){
    ll v = adj[u][i].first;
    ll wt = adj[u][i].second;

    if(v==par)continue;

    // nodes will contain the total number of nodes present in the tree subrooted at child 'v'
    ll nodes = dfs(u,v);
    ret+=2*min(nodes,n-nodes)*wt;
    ans+=nodes;
  }
  // ans contains the total number of nodes present in the tree subrooted at node 'u'
  return ans;
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  ll tc=1;
  while(t--){
    ret=0;
    s(n);
    F(i,1,n)adj[i].clear();

    F(i,1,n-1){
      ll u,v,x;
      s3(u,v,x);
      adj[u].pb({v,x});
      adj[v].pb({u,x});
    }

    dfs(-1,1);
    cout<<"Case #"<<tc++<<": "<<ret<<endl;
  }
}