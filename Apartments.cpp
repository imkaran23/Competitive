<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,m;

    cin>>n>>m>>k;

    int a[n], b[m];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    sort(a,a+n);
    sort(b,b+m);

    int i=0, j=0, ans=0;

    while(i<n && j<m){
        if(b[j]<=a[i]){
            if(a[i]-b[j]<=k)
                i++,j++,ans++;
            else
                j++;
        }
        else{
            if(b[j]-a[i]<=k)
                i++,j++,ans++;
            else
                i++;
        }
    }

    cout<<ans<<"\n";

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k,m;

    cin>>n>>m>>k;

    int a[n], b[m];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    sort(a,a+n);
    sort(b,b+m);

    int i=0, j=0, ans=0;

    while(i<n && j<m){
        if(b[j]<=a[i]){
            if(a[i]-b[j]<=k)
                i++,j++,ans++;
            else
                j++;
        }
        else{
            if(b[j]-a[i]<=k)
                i++,j++,ans++;
            else
                i++;
        }
    }

    cout<<ans<<"\n";

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}