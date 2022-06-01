<<<<<<< HEAD
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
    ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    ordered_set josep; 

	for(int i=1;i<=n;++i) josep.insert(i);

	int pos=0, k = 1;

	while(josep.size()>1){
		pos=(pos+k)%(int)josep.size();

		cout<<*(josep.find_by_order(pos))<<' ';

		josep.erase(*(josep.find_by_order(pos)));

		pos%=(int)josep.size();
	}

	cout<<*(josep.find_by_order(0))<<endl;

    return 0;
=======
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
    ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    ordered_set josep; 

	for(int i=1;i<=n;++i) josep.insert(i);

	int pos=0, k = 1;

	while(josep.size()>1){
		pos=(pos+k)%(int)josep.size();

		cout<<*(josep.find_by_order(pos))<<' ';

		josep.erase(*(josep.find_by_order(pos)));

		pos%=(int)josep.size();
	}

	cout<<*(josep.find_by_order(0))<<endl;

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}