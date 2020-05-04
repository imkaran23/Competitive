/*
B. T-shirt buying
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A new pack of n t-shirts came to a shop. Each of the t-shirts is characterized by three integers pi, ai and bi, where pi is the price of the i-th t-shirt, ai is front color of the i-th t-shirt and bi is back color of the i-th t-shirt. All values pi are distinct, and values ai and bi are integers from 1 to 3.

m buyers will come to the shop. Each of them wants to buy exactly one t-shirt. For the j-th buyer we know his favorite color cj.

A buyer agrees to buy a t-shirt, if at least one side (front or back) is painted in his favorite color. 
Among all t-shirts that have colors acceptable to this buyer he will choose the cheapest one. If there are no such t-shirts, the buyer won't buy anything. Assume that the buyers come one by one, and each buyer is served only after the previous one is served.

You are to compute the prices each buyer will pay for t-shirts.

Input
The first line contains single integer n (1 ≤ n ≤ 200 000) — the number of t-shirts.

The following line contains sequence of integers p1, p2, ..., pn (1 ≤ pi ≤ 1 000 000 000), where pi equals to the price of the i-th t-shirt.

The following line contains sequence of integers a1, a2, ..., an (1 ≤ ai ≤ 3), where ai equals to the front color of the i-th t-shirt.

The following line contains sequence of integers b1, b2, ..., bn (1 ≤ bi ≤ 3), where bi equals to the back color of the i-th t-shirt.

The next line contains single integer m (1 ≤ m ≤ 200 000) — the number of buyers.

The following line contains sequence c1, c2, ..., cm (1 ≤ cj ≤ 3), where cj equals to the favorite color of the j-th buyer. The buyers will come to the shop in the order they are given in the input. Each buyer is served only after the previous one is served.

Output
Print to the first line m integers — the j-th integer should be equal to the price of the t-shirt which the j-th buyer will buy. If the j-th buyer won't buy anything, print -1.

Examples
inputCopy
5
300 200 400 500 911
1 2 1 2 3
2 1 3 2 1
6
2 3 1 2 1 1
outputCopy
200 400 300 500 911 -1
inputCopy
2
1000000000 1
1 1
1 2
2
2 1
outputCopy
1 1000000000

#include<iostream>
#include<vector>
#include<set>
#include<iterator>
using namespace std;

int main()
{
    int n,x,m,c;
    vector<int> p,a,b;
    set<pair<int,int> > s;
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        p.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        b.push_back(x);
    }

    cin>>m;
    while(m--)
    {
        cin>>c;
        auto it1 = find(a.begin(),a.end(),c);
        auto it2 = find(b.begin(),b.end(),c);
        if (it1!=a.end())
        {
            cout<<p[it1]<<" ";
            a.erase(it1);
            b.erase(it1);
            p.erase(it1);
        }
        else if (it2!=b.end())
        {
            cout<<p[it2]<<" ";
            a.erase(it2);
            b.erase(it2);
            p.erase(it2);
        }
        else
        {
            cout<<"-1";
        }


    }

    return 0;
}
*/
#include<iostream>
#include<set>
using namespace std;

main(){
    int c,i,n,m,j,t;
    set<int> s[4];
	cin>>n;
    int p[n];
	for(i=0;i<3*n;i++)
    {
		cin>>c;
        if(i<n)
            p[i]=c;
        else
            s[c].insert(p[i%n]);
	}
	cin>>m;
	for(i=0;i<m;i++)
    {
		cin>>c;
		t=*s[c].begin();
		for(j=1;j<4;j++)
			s[j].erase(t);
		if(t)
            cout<<t<<" ";
		else 
            cout<<"-1 ";
	}
}