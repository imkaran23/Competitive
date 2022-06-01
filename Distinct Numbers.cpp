<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    set<int> s;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        s.insert(x);
    }

    cout<<s.size()<<"\n";
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    set<int> s;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        s.insert(x);
    }

    cout<<s.size()<<"\n";
    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}