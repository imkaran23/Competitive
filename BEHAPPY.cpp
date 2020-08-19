#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,v[21][101];


int recur(int girl, int N){
    if(girl<m && N<0) return 0;
    else if(girl==m && N!=0) return 0;
    else if( girl==m && N==0) return 1;

    long long count=0;

    for (long long i=v[girl][0]; i<=v[girl][1]; i++){
        int t = recur(girl+1, N-i);
        if(t) count+=t;
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;
    for (int i=0; i<=m; i++){
        cin>>a>>b;
        if(!a && !b) break;
        v[i][0]=a;
        v[i][1]=b;
    }
        
    cout<<recur(0,n)<<endl;
    return 0;
}