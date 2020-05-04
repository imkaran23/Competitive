/*
B. Ciel and Flowers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Fox Ciel has some flowers: r red flowers, g green flowers and b blue flowers. She wants to use these flowers to make several bouquets. There are 4 types of bouquets:

To make a "red bouquet", it needs 3 red flowers.
To make a "green bouquet", it needs 3 green flowers.
To make a "blue bouquet", it needs 3 blue flowers.
To make a "mixing bouquet", it needs 1 red, 1 green and 1 blue flower.
Help Fox Ciel to find the maximal number of bouquets she can make.

Input
The first line contains three integers r, g and b (0 ≤ r, g, b ≤ 109) — the number of red, green and blue flowers.

Output
Print the maximal number of bouquets Fox Ciel can make.

Examples
inputCopy
3 6 9
outputCopy
6
inputCopy
4 4 4
outputCopy
4
inputCopy
0 0 0
outputCopy
0
Note
In test case 1, we can make 1 red bouquet, 2 green bouquets and 3 blue bouquets.

In test case 2, we can make 1 red, 1 green, 1 blue and 1 mixing bouquet.

#include<iostream>
#include<algorithm>
using namespace std;

main()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    // cout<<a[0]<<a[1]<<a[2]<<endl;
    sort(a,a+3);
    int start=0,end=a[0],max=(a[0]) + (a[1]-a[0])/3 + (a[2]-a[0])/3;
    while(start<end)
    {
        int mid = start + (end-start)/2;
        cout<<mid<<endl;
        int total = (a[0]-mid) + (a[1]-a[0]+mid)/3 + (a[2]-a[0]+mid)/3 ;
        // cout<<a[0]-i<<" "<<(a[1]-a[0]+i)<<" "<<(a[2]-a[0]+i)<<" "<<total<<endl;
        if(total>max)
        {
            max=total;
            start = mid ;
        }
        else
        {
            end = mid ;
        }
    }
    cout<<max;
}
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned r, g, b;
    cin >> r >> g >> b;

    unsigned R(r % 3), G(g % 3), B(b % 3);
    unsigned amount(r / 3 + g / 3 + b / 3 + min(R, min(G, B)));
    if (   R == 2 && G == 2 && B == 0 && b != 0
        || G == 2 && B == 2 && R == 0 && r != 0
        || B == 2 && R == 2 && G == 0 && g != 0)
    {
        amount += 1;
    }
    cout << amount << endl;
    return 0;
}