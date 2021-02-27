#include <bits/stdc++.h>
using namespace std;
const long long int m = 10e9 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,x=1;
    unordered_set<int> s;
    s.insert(1);
    for(long long i=1;;i++){
        x = x + 6*i;
        if(x<m) s.insert(x);
        else break;
    }
    while(true){ 
        cin>>n;
        if(n==-1) break;
        if(s.find(n) != s.end())
            cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}