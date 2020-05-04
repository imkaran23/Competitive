/*
Bhelu is the classmate of Bablu who made the Amazing Prime Sequence .

He felt jealous of his classmate and decides to make his own sequence. Since he was not very imaginative, he came up with almost the same definition just making a difference in f(n):

a[0] = a[1] = 0.
For n > 1, a[n] = a[n - 1] + f(n), where f(n) is the sum of positive integers in the following set S.
S = {x | x < n and n % x = 0}.
Now, Bablu asked him to make a code to find f(n) as he already had the code of his sequence. So, Bhelu asks for your help since he doesn't know Programming. Your task is very simple, just find a[n] for a given value of n (< 10^6).

Input
Your code will be checked for multiple Test Cases.

First Line of Input contains T (<= 100), the number of Test Cases.

Next T lines contain a single positive integer N. (1 < N < 10^6).

Output
Single line containing a[n] i.e. n-th number of the sequence for each test case.

Example
Input:
3
3
4
5

Output:
2
5
6
Explanation

f(2) = 1 {1}
f(3) = 1 {1}
f(4) = 3 {1, 2}
f(5) = 1 {1}

*/

#include <bits/stdc++.h>

using namespace std;

const int me = 1000000;

int t, n;
long long int f[me];

int main()
{

    for(int i = 1; i < me; i ++)
        for(int j = 2*i; j < me; j += i){
                f[j] += i;
        }

    for(int i = 2; i < me; i ++){
        //cout<<f[i];
        f[i] += f[i - 1];
    }
    cin >> t;
    while(t --){
        cin >> n;
        cout << f[n] << endl;
    }

    return 0;
}
