/*
Simran and stairs
Attempted by: 2328/Accuracy: 87%/Maximum Score: 20/
 35 Votes
Tag(s): Easy, Recursion
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Simran is running up a staircase with N steps, and can hop(jump) either 1 step, 2 steps or 3 steps at a time.You have to count, how many possible ways Simran can run up to the stairs.

Input Format:
Input contains integer N that is number of steps

Output Format:
Output for each integer N the no of possible ways w.

Constraints

 

 

SAMPLE INPUT 
4
SAMPLE OUTPUT 
7
Time Limit:	0.15 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include<iostream>
using namespace std;

int steps(int n)
{
    if(n==2)
        return 2;
    if(n==0||n==1)
        return 1;
    return steps(n-1)+steps(n-2)+steps(n-3);
}

main()
{
    int n;
    cin>>n;
    cout<<steps(n);
}