#include<bits/stdc++.h>
using namespace std;

int n, x, y, q, k;
vector<vector<int>> go_up(20, vector<int>(200001));

int jump(int x, int k){
    for(int i = 0; i<20; i++) 
        if(  k>>i & 1 )
            x = go_up[i][x];
    
    if(x) return x;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;

    for(int i=2 ; i <=n; i++){
        cin>>x;
        go_up[0][i] = x;
    }

    for(int i = 1; i<20; i++){
        for(int j = 1; j<=n; j++){
            go_up[i][j] = go_up[i-1][go_up[i-1][j]];
        }
    }

    while(q--){
        cin>>x>>k;
        cout<< jump(x,k) << '\n';
    }
    
    return 0;
}

// TLE

// #include<bits/stdc++.h>
// using namespace std;

// int n, x, y, q, k;
// vector<int> b(200001); 

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin>>n>>q;

//     b[1] = -1;
//     for(int i=2 ; i <=n; i++){
//         cin>>x;
//         b[i] = x;
//     }


//     while(q--){
//         cin>>x>>k;

//         int ans = n+1;
//         while(k-- && ans!=-1){
//             ans = b[x];
//             x = b[x]; 
//         }
//         cout<<ans<<'\n';
//     }
    
//     return 0;
// }