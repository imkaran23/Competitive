#include <bits/stdc++.h>
using namespace std;
int h,w;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int recur(vector<vector<char>>& a,vector<vector<int>>& sol,char ch, int i, int j){
    if(sol[i][j]!=-1) return sol[i][j];

    int tmp = 1;
    for (int idx = 0; idx < 8; ++idx) {
        if (i+dx[idx] < 0 || i+dx[idx] >= h || j+dy[idx] < 0 || j+dy[idx] >= w) continue;

        if (a[i+dx[idx]][j+dy[idx]] == ch) {
            tmp = max(tmp, 1 + recur(a, sol, ch+1, i+dx[idx], j+dy[idx]));
        }
    }

    sol[i][j] = tmp;
    return tmp;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k=1;
    while(cin>>h>>w){
        if(h==0 && w==0) break;
        vector<vector<char>> a(h,vector<char>(w));
        vector<vector<int>> sol(h,vector<int>(w,-1));
        int ans=0;
        for(int i=0; i<h; i++) for(int j=0; j<w; j++) cin>>a[i][j];
        for(int i=0; i<h; i++) for(int j=0; j<w; j++){
            if(a[i][j]=='A') 
                ans = max(ans,recur(a, sol, 'A'+1, i, j));
        } 
        cout<<"Case "<<k<<": "<<ans<<"\n";
        k++;
    }
    return 0;
    
}
