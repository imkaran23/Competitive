#include <bits/stdc++.h>
using namespace std;

int main(){
    int l1, r1, l2, r2;
    cin>>l1>>r1>>l2>>r2;

    int z = min(r1, r2) - max(l1, l2);
    z = z>0?z:0;
    cout<< z <<'\n';

}