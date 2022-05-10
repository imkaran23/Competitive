#include<bits/stdc++.h>
using namespace std;

bool valid(int x, int y, int n, int m){
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    cin>>n>>m;

    char a[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];

    int ans = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]=='.'){
                ans++;
                q.push({i,j});

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    a[x][y] = '#';
                    q.pop();

                    for(int k = 0; k<4; k++){
                        int x1 = x + dx[k];
                        int y1 = y + dy[k];

                        if(valid(x1,y1,n,m) && a[x1][y1]=='.'){
                            q.push({x1,y1});
                            a[x1][y1] = '#';
                        }
                    }
                }
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}