/*
B. Cutting Carrot
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Igor the analyst has adopted n little bunnies. As we all know, bunnies love carrots. Thus, Igor has bought a carrot to be shared between his bunnies. Igor wants to treat all the bunnies equally, and thus he wants to cut the carrot into n pieces of equal area.

Formally, the carrot can be viewed as an isosceles triangle with base length equal to 1 and height equal to h. Igor wants to make n - 1 cuts parallel to the base to cut the carrot into n pieces. He wants to make sure that all n pieces have the same area. Can you help Igor determine where to cut the carrot so that each piece have equal area?

Illustration to the first example.
Input
The first and only line of input contains two space-separated integers, n and h (2 ≤ n ≤ 1000, 1 ≤ h ≤ 105).

Output
The output should contain n - 1 real numbers x1, x2, ..., xn - 1. The number xi denotes that the i-th cut must be made xi units away from the apex of the carrot. In addition, 0 < x1 < x2 < ... < xn - 1 < h must hold.

Your output will be considered correct if absolute or relative error of every number in your output doesn't exceed 10 - 6.

Formally, let your answer be a, and the jury's answer be b. Your answer is considered correct if .

Examples
inputCopy
3 2
outputCopy
1.154700538379 1.632993161855
inputCopy
2 100000
outputCopy
70710.678118654752
*/

#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

void calc(int n ,double area,int initial_height)
{
    area = area - area/n;
    if(n==1)
        return;
    double h = sqrt(2*initial_height*area);
    calc(n-1,area,initial_height);
    cout << fixed << setprecision(12) << h <<" "; 
}

main()
{
    int n,h;
    cin>>n>>h;
    double area = double(h)/2;
    calc(n,area,h);
}