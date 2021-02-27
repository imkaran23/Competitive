#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        long long int n,i=1;
        cin >> n;
        if(n==1){
            cout<<"TERM 1 IS 1/1"<<endl;
            continue;
        }

        while(i*(i-1)/2<n){
            i++;
        }
        i--;

        int k = n-((i-1)*i/2);
        // cout<<i<<" "<<k<<" ";
        if(i%2) cout<<"TERM "<<n<<" IS "<<i-k+1<<"/"<<k<<"\n";
        else cout<<"TERM "<<n<<" IS "<<k<<"/"<<i-k+1<<"\n";
    }
}