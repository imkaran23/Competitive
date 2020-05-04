/*
HS09EQ - Diophantine equation
no tags
Sometimes solving a Diophantine equation is very hard. But, for example, the equation a+b2+c3+d4=n has a trivial solution for every value of n. Your task is to determine the number of solutions of the equation for each given n, assuming that in the equation all the values a, b, c and d are non-negative integers.

Input
The first line of input contains an integer T, representing the number of test cases (T<20000).

The following T lines contain one non-negative integer n each, where n < 109.

Output
Output T lines, each containing the number of solutions of the respective equation for n.

Example
Input:
5
0
1
10
100
1000

Output:
1
4
19
148
1476

*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    int n, t;
    cin>>t;
    while(t--) {
        cin>>n;
        int n1, n2, n3;
        long long int r = 0;

        n1 = sqrt(sqrt(n * 1.0));
        for(int d = 0;d <= n1; d++) {
            n2 = n - d * d * d * d;
            int nc = pow(n2, 1.0/3) + 1;
            for(int c=0;c<=nc;c++) {
                n3 = n2 -c * c * c;
                if(n3 < 0) continue;
                r += sqrt(n3) + 1;
            }
        }
        cout<<r<<endl;
    }

    return 0;
}
