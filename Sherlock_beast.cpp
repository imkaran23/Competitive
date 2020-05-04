/*
Sherlock and The Beast

50.84 more points to get your gold badge!
Rank: 126498|Points: 799.16/850
Problem Solving
Your Sherlock and The Beast submission got 30.00 points.  
You are now 50.84 points away from the gold level for your problem solving badge.
Try the next challenge | Try a Random Challenge
Problem
Submissions
Leaderboard
Discussions
Editorial
Topics
Sherlock Holmes suspects his archenemy Professor Moriarty is once again plotting something diabolical. Sherlock's companion, Dr. Watson, suggests Moriarty may be responsible for MI6's recent issues with their supercomputer, The Beast.

Shortly after resolving to investigate, Sherlock receives a note from Moriarty boasting about infecting The Beast with a virus. He also gives him a clue: an integer. Sherlock determines the key to removing the virus is to find the largest Decent Number having that number of digits.

A Decent Number has the following properties:

Its digits can only be 3's and/or 5's.
The number of 3's it contains is divisible by 5.
The number of 5's it contains is divisible by 3.
It is the largest such number for its length.
Moriarty's virus shows a clock counting down to The Beast's destruction, and time is running out fast. Your task is to help Sherlock find the key before The Beast is destroyed!

For example, the numbers  and  are both decent numbers because there are  's and  's in the first, and  's in the second. They are the largest values for those length numbers that have proper divisibility of digit occurrences.

Function Description

Complete the decentNumber function in the editor below. It should print the decent number for the given length, or  if a decent number of that length cannot be formed.

decentNumber has the following parameter(s):

n: the integer length of the decent number to create
Input Format

The first line is an integer, , denoting the number of test cases.

The next  lines each contain an integer , the number of digits in the number.

Constraints



Output Format

Print the Decent Number having  digits; if no such number exists, tell Sherlock by printing -1.

Sample Input

4
1
3
5
11
Sample Output

-1
555
33333
55555533333
Explanation

For , there is no Decent Number having  digit (so we print ).
For ,  is the only possible number. (Decent Number Property 3).
For ,  is the only possible number. (Decent Number Property 2).
For ,  is the Decent Number. All other permutations of these digits are not decent (Decent Number Property 4).
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%3==0){
            while(n--){
                cout<<5;
            }
            cout<<endl;
        }
        else if(n%3==2 && n>=5){
            while (n--)
            {
                if(n>=5)
                    cout<<5;
                else
                    cout<<3;
            }
            cout<<endl;   
        }
        else if(n%3==1 && n>=10){
            while (n--)
            {
                if(n>=10)
                    cout<<5;
                else
                    cout<<3;
            }
            cout<<endl;
        } 
        else
        {
            cout<<-1<<endl;
        }
        
    }
    return 0;
}