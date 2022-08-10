#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;
int n, m, component, ans;
vector<int> p, len;

void init(){ 
    p.resize(n+1);
    for(int i=1; i<=n; i++) p[i] = i;
    len.resize(n+1,1);
}

int find(int x){
    if(x == p[x]) return x;
    return find(p[x]);
}

int merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a!=b){
        component--;
        if(len[a]>len[b]) swap(a,b);
        p[a] = b;
        len[b] += len[a];
        ans = max(ans, len[b]); 
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    ans = 1;
    component = n;
    init();

    while(m--){
        int a,b; 
        cin >> a >> b;
        merge(a, b);
        cout<< component <<' '<< ans <<'\n';
    }
    
    return 0;
}