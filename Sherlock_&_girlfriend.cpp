/*
B. Sherlock and his girlfriend
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Sherlock has a new girlfriend (so unlike him!). Valentine's day is coming and he wants to gift her some jewelry.

He bought n pieces of jewelry. The i-th piece has price equal to i + 1, that is, the prices of the jewelry are 2, 3, 4, ... n + 1.

Watson gave Sherlock a challenge to color these jewelry pieces such that two pieces don't have the same color if the price of one piece is a prime divisor of the price of the other piece. Also, Watson asked him to minimize the number of different colors used.

Help Sherlock complete this trivial task.

Input
The only line contains single integer n (1 ≤ n ≤ 100000) — the number of jewelry pieces.

Output
The first line of output should contain a single integer k, the minimum number of colors that can be used to color the pieces of jewelry with the given constraints.

The next line should consist of n space-separated integers (between 1 and k) that specify the color of each piece in the order of increasing price.

If there are multiple ways to color the pieces using k colors, you can output any of them.

Examples
inputCopy
3
outputCopy
2
1 1 2 
inputCopy
4
outputCopy
2
2 1 1 2
Note
In the first input, the colors for first, second and third pieces of jewelry having respective prices 2, 3 and 4 are 1, 1 and 2 respectively.

In this case, as 2 is a prime divisor of 4, colors of jewelry having prices 2 and 4 must be distinct.
*/

#include<iostream>
#include<cstring>
using namespace std;

main()
{
    int n;
    cin>>n;
    int a[n+2]={0};
    //memset(a,0,n+2*sizeof(a[0]));
    for(int i = 2; i < n+2; i ++)
    {
        if(!a[i])
        {
            a[i]=1;
            for(int j = i+i; j < n+2; j += i)
            {
                if(!a[j])
                    a[j] = 2;
            }
        }
    }

    if(n<=2)
        cout<<1<<endl;
    else
        cout<<2<<endl;
    
    for(int i = 2; i < n+2; i ++)
        cout<<a[i]<<" ";

}