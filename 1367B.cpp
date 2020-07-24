#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,false_at_even=0,false_at_odd=0;
        cin>>n;
        f(i,0,n-1){
            cin>>x;
            if(i%2==0 && x%2!=0) false_at_even++;
            else if(i%2!=0 && x%2==0) false_at_odd++;
        }

        if( false_at_odd>0 && false_at_even>0 && false_at_even==false_at_odd) cout<<false_at_odd<<endl;
        else if(false_at_odd==0 && false_at_even==0) cout<<0<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
