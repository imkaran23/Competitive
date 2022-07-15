#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int maxN = 2000001;
int s_tree[4*maxN], a[maxN], n, q, x;

void build(int node = 1, int l = 1, int r = n){
    if(l==r) {
        s_tree[node] = a[l];
        return;
    }

    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    s_tree[node] = max(s_tree[node*2], s_tree[node*2+1]);
}

void queryUpdate(int val, int node = 1, int l = 1, int r = n){
    if(l==r){
        s_tree[node] -= val;
        cout<<l<<' ';
        return;
    }

    int mid = (l+r)/2;
    if(s_tree[node*2] >= val) queryUpdate(val, node*2, l, mid);
    else queryUpdate(val, node*2+1, mid+1, r);
    s_tree[node] = max(s_tree[node*2], s_tree[node*2+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;

    for(int i=1; i<=n; i++) cin>>a[i];

    build();

    for(int i=0; i<q; i++){
        cin>>x;
        if(x > s_tree[1]) cout<<0<<' ';
        else queryUpdate(x);
    }
    return 0;
}

// ========>> You always assign a group to the first hotel having enough rooms.

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// void printh(vector<pair<int,int>>& v){
//     for(auto x : v) cout<<x.first<<' ';
//     cout<<'\n';
// }

// void printg(vector<tuple<int,int,int>>& v){
//     for(auto x : v) cout<<get<0>(x)<<' ';
//     cout<<'\n';
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ll n,m,a,b,x;
//     cin>>n>>m;

//     vector<pair<int,int>> h;
//     vector<tuple<int, int, int>> g;

//     for(int i=0; i<n; i++){
//         cin >> x;
//         h.push_back({x, i+1});
//     }

//     for(int i=0; i<m; i++){
//         cin >> x;
//         g.push_back({x,i,0});
//     }

//     sort(h.begin(), h.end());
//     sort(g.begin(), g.end());
//     // printh(h);
//     // printg(g);

//     int i = 0, j = 0;

//     while(i<n && j<m){
//         tuple<int,int,int>& x = g[j];
//         int tmp = get<0>(x);
//         // cout<<tmp<<' ';

//         if(h[i].first >= tmp){
//             h[i].first -= tmp;
//             j++;
//             get<2>(x) = h[i].second;
//         }
//         else{
//             i++;
//         }
//     }

//     // cout<<'\n';
//     // printg(g);
//     auto cmp = [] (tuple<int,int,int> t1, tuple<int,int,int> t2){
//         return get<1>(t1) < get<1>(t2);
//     };

//     sort(g.begin(), g.end(), cmp);
//     // printg(g);

//     for(auto x : g) cout<<get<2>(x)<<' ';

//     return 0;
// }