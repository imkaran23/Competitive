#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)
int a[51][51],n,m;

bool isvalid(int x, int y){
    f(i,0,m-1) if(a[x][i]) return false;
    
    f(i,0,n-1) if(a[i][y]) return false;
    
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        f(i,0,n-1){
            f(j,0,m-1){
                cin>>a[i][j];
            }
        }

        int result = 0;

        f(i,0,n-1){
            f(j,0,m-1){
                if(isvalid(i,j)){
                    a[i][j] = 1;
                    result++;
                    break;
                }
            }
        }

        if(result%2 == 0) cout<<"Vivek\n";
        else cout<<"Ashish\n";
    }
    return 0;
}