/*
TRT - Treats for the Cows
#dynamic-programming

FJ has purchased N (1 <= N <= 2000) yummy treats for the cows who get money for giving vast amounts of milk. FJ sells one treat per day and wants to maximize the money he receives over a given period time. The treats are interesting for many reasons:

The treats are numbered 1..N and stored sequentially in single file in a long box that is open at both ends. On any day, FJ can retrieve one treat from either end of his stash of treats.
Like fine wines and delicious cheeses, the treats improve with age and command greater prices.
The treats are not uniform: some are better and have higher intrinsic value. Treat i has value v(i) (1 <= v(i) <= 1000).
Cows pay more for treats that have aged longer: a cow will pay v(i)*a for a treat of age a.
Given the values v(i) of each of the treats lined up in order of the index i in their box, what is the greatest value FJ can receive for them if he orders their sale optimally?

The first treat is sold on day 1 and has age a=1. Each subsequent day increases the age by 1.

Input
Line 1: A single integer, N

Lines 2..N+1: Line i+1 contains the value of treat v(i)

Output
The maximum revenue FJ can achieve by selling the treats

Example
Input:
5
1
3
1
5
2

Output:
43
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int dp[2003][2003], v[2003];
 
int solve(int l, int r){
    int age = (l - 1) + (n - r) + 1;
    if(l == r){
        return dp[l][r] = age * v[l];
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    int sell_first = age * v[l] + solve(l + 1, r);
    int sell_last = age * v[r] + solve(l, r - 1);
    return dp[l][r] = max(sell_first, sell_last);
}
 
main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(1, n)<<endl;
}