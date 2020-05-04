/*
Maricruz have a lot of cards, she always uses her cards to build pyramids as shown in the following image:

Cards
A pyramid card of 3 levels. She always wonder how many cards does she need to make a pyramid card of N levels. Your task is to answer that question.

Input
The first line of the input contains an integer 1 <= T <= 1,000. Each of the following T lines will have an integer 1 <= N <= 1,000,000.

Output
For each case, output a single line consisting of the number of cards needed to build a pyramid card of level N modulo 1,000,007.

Example
Input Example
2
3
7

Output Example
15
77

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int n,x,j = 0;
    long long int count;
    cin >> n;
    long long int ans[n];
    while(n--)
    {

        cin >> x;

        count = (x*2 + ((x-1)*x*3)/2)% 1000007 ;
        ans[j] = count;
        j++;
    }
    for(int i = 0; i < j; i++){
        cout<<ans[i] << endl;
    }
    return 0;
}
