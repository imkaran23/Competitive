#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[20],b,sum=0;
    double V;
    cin>>n>>V;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b;
        double x = sum*b/(double)a[i];
        V = min(V,x);
    }
    printf("%.4f\n", V);
    return 0;
}