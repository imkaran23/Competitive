#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,t,x,y;
    cin>>n>>k;
    vector<int> a,b,ab;

    while(n--){
        cin>>t>>x>>y;
        if(x==1 && y==1) ab.push_back(t);
        else if(x==1 && y==0) a.push_back(t);
        else if(x==0 && y==1) b.push_back(t);
    }

    sort(ab.begin(),ab.end());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0,j=0,ij=0,result=0;

    if(a.size() + ab.size()<k || b.size() + ab.size() <k) {cout<<-1<<endl; return 0;}

    while(k--){
        if(i<a.size() && j<b.size() && ij<ab.size()){
            if(a[i]+b[j]<ab[ij]){ result += a[i]+b[j] ; i++; j++;}
            else {result += ab[ij] ; ij++;}
        }
        else if(i<a.size() && j<b.size()){ result += a[i]+b[j] ; i++; j++;}
        else {result += ab[ij] ; ij++;}
    }

    cout<<result<<endl;
}