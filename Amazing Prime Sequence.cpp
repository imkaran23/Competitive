/* Bablu is very fond of Series and Sequences...

After studying Fibonacci Series in Class IX, he was impressed and he designed his own sequence as follows...

a[0] = a[1] = 0

For n > 1, a[n] = a[n - 1] + f(n), where f(n) is smallest prime factor of n.

He is also very fond of programming and thus made a small program to find a[n], but since he is in Class IX, he is not very good at programming. So, he asks you for help. Your task is to find a[n] for the above sequence....

Input
Your code will be checked for multiple Test Cases.

First Line of Input contains T (<= 100), the number of Test Cases.

Next T lines contain a single number N. (1 < N < 10^7).

Output
Single line containing a[n] i.e. nth number of the sequence for each test case.

Example
Input:
3
2
3
4

Output:
2
5
7*/

#include <bits/stdc++.h>

using namespace std;

const int me = 10000025;

int t, n;
long long int f[me];

int main()
{


    for(int i = 2; i < me; i ++)
        if(!f[i])
        for(int j = i; j < me; j += i){
            if(!f[j])
                f[j] = i;
        }

    for(int i = 1; i < me; i ++){
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
