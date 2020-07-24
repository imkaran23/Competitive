#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,t,x,y,m,z=0;
    cin>>n>>m>>k;
    vector<pair<int,int> > a,b,ab;
    vector<int> res;

    while(n--){
        cin>>t>>x>>y;
        if(x==1 && y==1) ab.push_back(make_pair(t,z));
        else if(x==1 && y==0) a.push_back(make_pair(t,z));
        else if(x==0 && y==1) b.push_back(make_pair(t,z));
        z++;
    }

    sort(ab.begin(),ab.end());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    a.push_back(make_pair(INT_MAX,INT_MAX)); b.push_back(make_pair(INT_MAX,INT_MAX)); ab.push_back(make_pair(INT_MAX,INT_MAX));

    int i=0,j=0,ij=0,result=0;

    if(a.size()-1 + ab.size()-1 <k || b.size()-1 + ab.size()-1 <k) {cout<<-1<<endl; return 0;}

    for(z=1; z<=m; z++){
        if(z<=k){
            if(i<a.size()-1 && j<b.size()-1 && ij<ab.size()-1){
                if(a[i].first +b[j].first < ab[ij].first){ 
                    result += a[i].first + b[j].first ; 
                    res.push_back(a[i].second); res.push_back(b[j].second); 
                    i++; j++;
                }
                else {
                    result += ab[ij].first ; 
                    res.push_back(ab[ij].second); 
                    ij++;
                }
            }
            else if(i<a.size()-1 && j<b.size()-1){ 
                result += a[i].first + b[j].first ; 
                res.push_back(a[i].second); res.push_back(b[j].second); 
                i++; j++;
            }
            else {
                result += ab[ij].first ; 
                res.push_back(ab[ij].second); 
                ij++;
            }
        }

        else{
           if(a[i].first < b[j].first){
               if(a[i].first < ab[ij].first) {
                   result += a[i].first ; 
                   res.push_back(a[i].second); 
                   i++;
                }
               else {
                   result += ab[ij].first ; 
                   res.push_back(ab[ij].second); 
                   ij++;
                }
           } 
           else{
               if(b[j].first < ab[ij].first) {
                   result += b[j].first ; 
                   res.push_back(b[j].second); 
                   j++;
                }
               else {
                   result += ab[ij].first ; 
                   res.push_back(ab[ij].second); 
                   ij++;
                }
           }
        }
    }

    cout<<result<<endl;
    for(z=0; z<res.size(); z++) cout<<res[z]<<" ";
}