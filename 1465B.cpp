#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,n,x,ans;
    cin>>t;
    while(t--){
        cin>>n;

        for (long long  i = n; i <= INT64_MAX; i++)
        {
            vector<int> v(10,0);
            x=i;
            while(x>0){
                if(x%10){ 
                    v[x%10]=1;    
                }
                x/=10;
            }

            bool flag = true;
            for (size_t j = 2; j < 10; j++)
            {
                if(v[j] && i%j!=0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<i<<"\n";
                break;
            }            
        }
    }
    return 0;
}