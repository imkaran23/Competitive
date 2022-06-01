<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

void knapSack(int W, int wt[], int n)
{
    int i, w;
    vector<vector<bool>> K(n + 1, vector<bool>(W + 1));
 
    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(w==0)
                K[i][w] = true;
            else if (i == 0)
                K[i][w] = false;
            else if (wt[i - 1] <= w)
                K[i][w] = K[i - 1][w - wt[i - 1]] || K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    int ans = 0;
    for(int j=1; j<=W; j++)
        if(K[n][j])
            ans++;   
    cout<<ans<<'\n';

    for(int j=1; j<=W; j++)
        if(K[n][j])
            cout<<j<<" ";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n], sum = 0;

    for(int i=0; i<n; i++){ 
        cin>>a[i];
        sum += a[i];
    }

    knapSack(sum, a, n);
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

void knapSack(int W, int wt[], int n)
{
    int i, w;
    vector<vector<bool>> K(n + 1, vector<bool>(W + 1));
 
    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(w==0)
                K[i][w] = true;
            else if (i == 0)
                K[i][w] = false;
            else if (wt[i - 1] <= w)
                K[i][w] = K[i - 1][w - wt[i - 1]] || K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    int ans = 0;
    for(int j=1; j<=W; j++)
        if(K[n][j])
            ans++;   
    cout<<ans<<'\n';

    for(int j=1; j<=W; j++)
        if(K[n][j])
            cout<<j<<" ";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n], sum = 0;

    for(int i=0; i<n; i++){ 
        cin>>a[i];
        sum += a[i];
    }

    knapSack(sum, a, n);
    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}