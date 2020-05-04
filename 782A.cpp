/*
A. Andryusha and Socks
time limit per test 2 seconds
memory limit per test 256 megabytes
inpu tstandard input
output standard output
Andryusha is an orderly boy and likes to keep things in their place.

Today he faced a problem to put his socks in the wardrobe. He has n distinct pairs of socks which are initially in a bag. 
The pairs are numbered from 1 to n. Andryusha wants to put paired socks together and put them in the wardrobe. 
He takes the socks one by one from the bag, and for each sock he looks whether the pair of this sock has been already took out of the bag, or not. 
If not (that means the pair of this sock is still in the bag), he puts the current socks on the table in front of him. Otherwise, 
he puts both socks from the pair to the wardrobe.

Andryusha remembers the order in which he took the socks from the bag. 
Can you tell him what is the maximum number of socks that were on the table at the same time?

Input
The first line contains the single integer n (1 ≤ n ≤ 105) — the number of sock pairs.

The second line contains 2n integers x1, x2, ..., x2n (1 ≤ xi ≤ n), which describe the order in which Andryusha took the socks from the bag. 
More precisely, xi means that the i-th sock Andryusha took out was from pair xi.

It is guaranteed that Andryusha took exactly two socks of each pair.

Output
Print single integer — the maximum number of socks that were on the table at the same time.

Examples
inputCopy
1
1 1
outputCopy
1
inputCopy
3
2 1 1 3 2 3
outputCopy
2
Note
In the first example Andryusha took a sock from the first pair and put it on the table. Then he took the next sock which is from the first pair 
as well, so he immediately puts both socks to the wardrobe. Thus, at most one sock was on the table at the same time.

In the second example Andryusha behaved as follows:

Initially the table was empty, he took out a sock from pair 2 and put it on the table.
Sock (2) was on the table. Andryusha took out a sock from pair 1 and put it on the table.
Socks (1, 2) were on the table. Andryusha took out a sock from pair 1, and put this pair into the wardrobe.
Sock (2) was on the table. Andryusha took out a sock from pair 3 and put it on the table.
Socks (2, 3) were on the table. Andryusha took out a sock from pair 2, and put this pair into the wardrobe.
Sock (3) was on the table. Andryusha took out a sock from pair 3 and put this pair into the wardrobe.
Thus, at most two socks were on the table at the same time.
*/

#include<iostream>
using namespace std;
int a[210];

int main()
{
    ios_base::sync_with_stdio(false);
    int n,k=0,max=0,s;
    cin>>n;
    for(int i=0; i<2*n ; i++)
    {
        cin>>s;
        if(k>max)
            max=k;
        if(a[s]==0)
        {
            k++;
            a[s]=1;
        }
        else
            k--;
    }
    cout<<max;
    return 0; 
}














