#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n][n];
        
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                a[i][j]=0;
            }
        }

        for(int i=0; i<n-2; i++){
            for(int j=n-2; j<n; j++){
                a[i][j]=1;
            }
        }

        for(int i=n-2; i<n; i++){
            for(int j=0; j<n-2; j++){
                a[i][j]=1;
            }
        }

        int diff = 113 - n + 2;
        for(int i = 1; i<=diff/2; i++){
            if( !isPrime(i) && !isPrime(diff-i)){
                a[n-2][n-2] = i;
                a[n-1][n-1] = i;
                a[n-2][n-1] = diff-i;
                a[n-1][n-2] = diff-i;
                break;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}