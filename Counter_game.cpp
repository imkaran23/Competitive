/*
Louise and Richard have developed a numbers game. They pick a number and check to see if it is a power of . If it is, they divide it by . If not, they reduce it by the next lower number which is a power of . Whoever reduces the number to  wins the game. Louise always starts.

Given an initial value, determine who wins the game.

As an example, let the initial value . It's Louise's turn so she first determines that  is not a power of . The next lower power of  is , so she subtracts that from  and passes  to Richard.  is a power of , so Richard divides it by  and passes  to Louise. Likewise,  is a power so she divides it by  and reaches . She wins the game.

Update If they initially set counter to , Richard wins. Louise cannot make a move so she loses.

Function Description

Complete the counterGame function in the editor below. It should return the winner's name, either Richard or Louise.

counterGame has the following parameter(s):

n: an integer to initialize the game counter
Input Format

The first line contains an integer , the number of testcases.
Each of the next  lines contains an integer , the initial value for the game.

Constraints

Output Format

For each test case, print the winner's name on a new line in the form Louise or Richard.

Sample Input 0

1
6
Sample Output 0

Richard
Explanation 0

 is not a power of  so Louise reduces it by the largest power of  less than :.
 is a power of  so Richard divides by  to get  and wins the game.
*/
#include <bits/stdc++.h>
using namespace std;

string counterGame(long n) {
    int cnt = 0;
    while (n != 1)
    {
        int len = 0;
        long tmp = n;
        while (tmp != 0) tmp /= 2, len++;
        long a = (long)1 << (len - 1);
        if (n == a) n /= 2;
        else n -= a;
        cnt++;
    }
    if (cnt % 2 == 0) return "Richard";
    else return "Louise";
}

main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        cout<<counterGame(n)<<endl;
    }
}