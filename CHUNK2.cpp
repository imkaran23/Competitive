/*
CHUNK2 - Popatlal ki shaadi
no tags 



Popatlal from Gokuldham Society is still not married.He approaches a marriage bureau and ask them to hurry the process.The bureau checks the list of eligible girls (n) and hands it over to Popatlal.Popatlal being conscious about his marriage, determined to find a girl with maximum connections so that he can gather more information about her.Accordingly, he looks to figure out the maximum number of girls (from list) who know each other to achieve above purpose.In order to finalise the girl,he needs to find the Kth prime.Where k  = largest group of girls who know each other .Considering Popat's poor knowledge in Maths, he seeks for Jethalal's help for the answer. Now you , being fan of Jethalal, take this prestigious opportunity to solve Popat's marriage issue.In case no of connections are zero ,print "-1".Note : Suppose girl "a" knows girl "b" and girl "b" knows girl "c" , then girl "a" also knows girl "c".Transitivity holds.Consider 1 composite no.
Popatlal from Gokuldham Society is still not married.

He approaches a marriage bureau and ask them to hurry the process.

The bureau checks the list of eligible girls (n) and hands it over to Popatlal.

Popatlal being conscious about his marriage, determined to find a girl with maximum connections so that he can gather more information about her.

Accordingly, he looks to figure out the maximum number of girls (from list) who know each other to achieve above purpose.

In order to finalise the girl,he needs to find the Kth prime.

Where k  = largest group of girls who know each other .

Considering Popat's poor knowledge in Maths, he seeks for Jethalal's help for the answer. Now you , being fan of Jethalal, take this prestigious opportunity to solve Popat's marriage issue.

In case no of connections are zero ,print "-1".

Note : Suppose girl "a" knows girl "b" and girl "b" knows girl "c" , then girl "a" also knows girl "c".

Transitivity holds.

Consider 1 composite no.



Input:

First line of the input contains t, the number of test cases.

Each line of the test case contains a number n specifying the number of girls and m specifying no of connections.

Each 'm' lines contain u and v denoting that girl u and v know each other.



Output:
Each new line of the output contains Kth prime no .



Constraints:

1<=t<=100

1<=n<=100000

0<=m<=n

1<=u,v<=n



Example:
Input:
1
10 6
1 2
2 3
3 4
4 5
6 7
9 10

  Output:  
11
#include<iostream>
#include<cstring>
#include<limits.h>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
int prime[100000],vis[100001],cnt;
vector<vector<int> > v;
vector<int> kprime;

void dfs(int x){
    vis[x]=1;
    cnt++;
    f(i,0,v[x].size()-1){
        if(!vis[v[x][i]])
            dfs(v[x][i]);
    }
}


int main(){
    memset(prime,0,sizeof(prime));
    f(i,2,99999){
            if(!prime[i]){
            kprime.push_back(i);
            for(int j=2*i;j<100000;j+=i){
                prime[j]=1;
            }   
        }
    }

    int t,n,m,a,b,maxi;
    cin>>t;
    while (t--){
        cin>>n>>m;
        v.clear();
        v.resize(n+1);
        f(k,1,m){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        memset(vis,0,sizeof(vis));
        maxi=0;
        f(i,1,n){
            cnt=0;
            if(!vis[i])
                dfs(i);
            if(cnt>maxi)
                maxi=cnt;
        }
        if(m==0)
            cout<<-1<<endl;
        else
            cout<<kprime[maxi-1]<<endl;     
    }
    return 0;
}
*/
#include <iostream>
#include <vector>

using namespace std;

const int S = 1 << 21;

int T, N, M;
vector<int> was;

void dfs(int node, vector<vector<int>> &graph, int &size) {
    was[node] = 1;
    ++size;
    for (int neighbor: graph[node]) {
        if (!was[neighbor]) {
            dfs(neighbor, graph, size);
        }
    }
}

int main() {
    vector<int> primes(S, 1);
    vector<int> primelist;
    primes[1] = 0;
    for (int i = 2; i < S; i ++) {
        if (!primes[i]) {
            continue;
        }
        primelist.push_back(i);
        for (int j = i + i; j < S; j += i) {
            primes[j] = 0;
        }
    }
    
    cin >> T;
    while (T --) {
        cin >> N >> M;
        vector<vector<int>> graph(N + 1);
        was.assign(N + 1, 0);
        for (int i = 0; i < M; i ++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int best = -1;
        for (int i = 1; i <= N; i ++) {
            if (was[i]) {
                continue;
            }
            int size = 0;
            dfs(i, graph, size);
            if (size > best) {
                best = size;
            }
        }
        if (M == 0) {
            cout << -1 << endl;
        } else {
            cout << primelist[best - 1] << endl;
        }
    }
    
    return 0;
}