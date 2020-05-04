/*
The Magical Shop
Attempted by: 5269/Accuracy: 82%/Maximum Score: 20/
 170 Votes
Tag(s): Ad-Hoc, Easy, Mathamatics, Mathematics
PROBLEM

EDITORIAL

MY SUBMISSIONS
There is a magical shop owned by The Monk, which consists of magical potions. On the first day there are A number of potions. Let, potions[I] denote the number of potions present in the shop on the Ith day.

potions[I] = potions[I-1] * potions[I-1]
You, Monk's favorite student love to play around with various types of potions. So, you visit the shop regularly and buy all the potions and just keep them with yourself. However, the Monk allows you to go to the shop only on specific days.

You have to find the number of potions that you will have at the very end. Since, the answer can be very large, output it modulo B.

Input Format:
The first line will contain A and B, the number of potions on the first day and the value with which modulo is to be taken. The second line consists of a string consisting of "0" and "1". If the Ith character from left is 1 then you can go to shop on Ith day to buy potions.

Output Format:
Output on a single line, the number of potions that you will have at the end. Since, the answer can be very large, output it modulo B.

Constraints:
1 <= A, B <= 109
1 <= |Length of the string| <= 105
The string will only consist of 1 and 0.

SAMPLE INPUT
5 100
101
SAMPLE OUTPUT
30
Explanation
On the first day, the number of potions are 5. Since The Monk allowed you to go to the magical shop to buy the potions. He buy all the potions, you have 5 potions now.
On the second day, the number of potions are 5*5 = 25. Since, the number of potions in the shop on the first day restores to 5 after you leave the shop. However, you cannot go to the shop on the second day, since The Monk doesn't allow you.
On the third day, the number of potions are 25*25 = 625. Since The Monk allowed him to go to the magical shop to buy the potions. He buys all the potions, he has 5+625 = 630 potions.
The answer must be given modulo B, 630 mod 100 = 30
Time Limit:	5.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
 
main()
{
    long long int p , m , total ;
    string s;
 
    cin>>p>>m>>s;
 
    for ( char c : s)
    {
        if (c=='1')
            total = (total+p)%m;
        p = (p*p) % m ;
    }
    
    cout<<total;
}
