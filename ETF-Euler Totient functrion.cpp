/*
In number theory, the totient φ of a positive integer n is defined to be the number of positive integers less than or equal to n that are coprime to n.

Given an integer n (1 <= n <= 10^6). Compute the value of the totient φ.

Input
First line contains an integer T, the number of test cases. (T <= 20000)

T following lines, each contains an integer n.

Output
T lines, one for the result of each test case.

Example
Input:
5
1
2
3
4
5

Output:
1
1
2
2
4



#include<bits/stdc++.h>
using namespace std;

const long long siz=1000002;
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


    int N;
    long long n;
    double ans ;
    cin >> N ;

    while( N-- )
    {
        cin >> n ;
        ans = n ;
        for ( long long i =0 ; i < k ; i++ )
        {
            if( n % b[i] == 0 )
                ans *= 1- 1/double(b[i]) ;
        }

        cout << ans << endl ;
    }

    return 0;
}

*/

#include <iostream>
using namespace std;
typedef long long LL;

LL etf (LL n) {
	LL i, result = n;
	for( i = 2 ;i*i <= n ; i++) {
   		if (n % i == 0) result -= result / i;

    	while (n % i == 0) n /= i;
	}
	if (n > 1) result -= result / n;
	return result;
}

int main() {
	LL t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << etf (n) << endl ;
	}
	return 0;
}
