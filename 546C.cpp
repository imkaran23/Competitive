/*
C. Soldier and Cards
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Two bored soldiers are playing card war. Their card deck consists of exactly n cards, numbered from 1 to n, all values are different. They divide cards between them in some manner, it's possible that they have different number of cards. Then they play a "war"-like card game.

The rules are following. On each turn a fight happens. Each of them picks card from the top of his stack and puts on the table. The one whose card value is bigger wins this fight and takes both cards from the table to the bottom of his stack. More precisely, he first takes his opponent's card and puts to the bottom of his stack, and then he puts his card to the bottom of his stack. If after some turn one of the player's stack becomes empty, he loses and the other one wins.

You have to calculate how many fights will happen and who will win the game, or state that game won't end.

Input
First line contains a single integer n (2 ≤ n ≤ 10), the number of cards.

Second line contains integer k1 (1 ≤ k1 ≤ n - 1), the number of the first soldier's cards. Then follow k1 integers that are the values on the first soldier's cards, from top to bottom of his stack.

Third line contains integer k2 (k1 + k2 = n), the number of the second soldier's cards. Then follow k2 integers that are the values on the second soldier's cards, from top to bottom of his stack.

All card values are different.

Output
If somebody wins in this game, print 2 integers where the first one stands for the number of fights before end of game and the second one is 1 or 2 showing which player has won.

If the game won't end and will continue forever output  - 1.

Examples
inputCopy
4
2 1 3
2 4 2
outputCopy
6 2
inputCopy
3
1 2
2 1 3
outputCopy
-1
*/
#include<iostream>
#include<queue>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    queue<int> q1,q2;
    int n,k1,k2,x,count=0,winner;
    cin>>n;
    cin>>k1;
    while(k1--)
    {
        cin>>x;
        q1.push(x);
    }
    cin>>k2;
    while(k2--)
    {
        cin>>x;
        q2.push(x);
    }
 
    while(count<1001)
    {
        if(q1.empty())
        {    
            winner=2;
            break;
        }
        else if(q2.empty())
        {    
            winner=1;
            break;
        }
        else if(q1.front()>q2.front())
        {
            q1.push(q2.front());
            q1.push(q1.front());
            q1.pop();
            q2.pop();
            count++;
        }
        else
        {
            q2.push(q1.front());
            q2.push(q2.front());
            q2.pop();
            q1.pop();
            count++;
        }
        
    }
 
    if(count>1000)
        cout<<-1;
    else
        cout<<count<<" "<<winner;
    return 0;
}