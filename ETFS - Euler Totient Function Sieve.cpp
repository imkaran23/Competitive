/*
In number theory, the totient phi(n) of a positive integer n is defined to be the number of positive integers less than or equal to n that are coprime to n.

Input
The lonely line in input contains two integers a, b.

Output
Print phi(n) for n from a to b (inclusive).

Example
Input:
1 5

Output:
1
1
2
2
4

Constraints
0 < a < b < 10^14
b - a < 10^5
Python can get AC under half the time limit (for any test case). My total PY3.4 time is 3.23s for 5 input files.
Have fun ;-)



#include <iostream>
using namespace std;
typedef long long LL;

LL etf (LL n) {
	LL i, result = n;
	for( i = 2 ;i*i <= n ; i++) {
   		if (n % i == 0) result -= result / i;

    	while (n % i == 0) n /= i;
	}
	if (n > 1)
        result -= result / n;
	return result;
}

int main() {
	LL a, b ;
	scanf("%d %d", & a , & b );
	cout<< a << ' ' << b << endl;

    for( LL i = a ; i <= b ; i++ )
        cout << etf (i) << endl ;
	return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;

const long long siz=1000001;
long long a[siz],b[siz];

int main()
{

	long long k=0;
    for (long long i = 2; i * i < siz; ++i)
    {
        if(!a[i])
        {
            for (long long j = i*i ; j < siz; j += i)
            {
                a[j]=1;
            }
        }
    }

    for ( long long i =2 ; i < siz ; i++ )
    {
    	if(!a[i])
    	{
    		b[k]=i;
    		k++;
    	}
    }

    double ans ;

    long long  a, b ;
	scanf("%d %d", & a , & b );
	cout<< a << ' ' << b << endl;

    for( long long j = a ; j <= b ; j++ )
    {
        ans = j ;
        for ( long long i =0 ; i < k ; i++ )
        {
            if( j % b[i] == 0 )
                ans *= 1- 1/double(b[i]) ;
        }

        cout << ans << endl ;
    }

    return 0;
}
