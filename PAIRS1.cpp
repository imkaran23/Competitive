/*
PAIRS1 - Count the Pairs
#sorting #array #binary-search


Given N integers [N<=10^5], count the total pairs of integers that have a difference of K. [K>0 and K<1e9]. Each of the N integers will be greater than 0 and at least K away from 2^31-1 (Everything can be done with 32 bit integers).Input Format1st line contains N & K (integers).2nd line contains N numbers of the set. All the N numbers are assured to be distinct.Output FormatOne integer saying the number of pairs of numbers that have a diff K.Sample Input #00:5 2  1 5 3 4 2  Sample Output #00:3Sample Input #01:10 1  363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793 Sample Output #01:0
Given N integers [0<N<=10^5], count the total pairs of integers that have a difference of K. (Everything can be done with 32 bit integers).



Input Format



1st line contains N & K (integers).

2nd line contains N numbers of the set. All the N numbers are distinct.



Output Format



One integer - the number of pairs of numbers that have a diff K.



Sample Input :

5 2

1 5 3 4 2

Sample Output :

3

Sample Input :

10 1

363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 1069262793

Sample Output :

0
*/
#include<iostream>
#include<set>
#include<math.h>
using namespace std;

main()
{
    set<int> s;
    int n,k,x,y1,y2,count=0;
    cin>>n>>k;
    while(n--)
    {
        cin>>x;
        y1=abs(x-k);
        y2=x+k;
        auto pos1 = s.find(y1);
        auto pos2 = s.find(y2);
        if(pos1!=s.end())
            count++;
        if(pos2!=s.end())
            count++;
        s.insert(x);
    }
    cout<<count<<endl;
}
