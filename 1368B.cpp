#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = int(a) ; i<=int(b) ; i++)

int main(){
    long long k, p=1;
    cin>>k;
    string s = "codeforces";
    vector<long long> v(10,1);
    for(long long i=0; p<k; i = (i+1)%10){
        v[i]++;
        p = (v[i]*p)/(v[i]-1);
    }

    for(long long i=0; i<10; i++) while(v[i]--) cout<<s[i];
    return 0;
}