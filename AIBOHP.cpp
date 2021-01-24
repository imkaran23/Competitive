/*
AIBOHP - Aibohphobia
#dynamic-programming

BuggyD suffers from AIBOHPHOBIA - the fear of Palindromes. A palindrome is a string that reads the same forward and backward.

To cure him of this fatal disease, doctors from all over the world discussed his fear and decided to expose him to large number of palindromes. To do this, they decided to play a game with BuggyD. The rules of the game are as follows:

BuggyD has to supply a string S. The doctors have to add or insert characters to the string to make it a palindrome. Characters can be inserted anywhere in the string.

The doctors took this game very lightly and just appended the reverse of S to the end of S, thus making it a palindrome. For example, if S = "fft", the doctors change the string to "ffttff".

Nowadays, BuggyD is cured of the disease (having been exposed to a large number of palindromes), but he still wants to continue the game by his rules. He now asks the doctors to insert the minimum number of characters needed to make S a palindrome. Help the doctors accomplish this task.

For instance, if S = "fft", the doctors should change the string to "tfft", adding only 1 character.

Input
The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of one line, the string S. The length of S will be no more than 6100 characters, and S will contain no whitespace characters.

Output
For each test case output one line containing a single integer denoting the minimum number of characters that must be inserted into S to make it a palindrome.

Example
Input:
1
fft

Output:
1
*/
#include<iostream>
#include<cstring>
#include<limits.h>
#include<algorithm>
using namespace std;
int dp[6102][6102];

int palin(string &str){
    for(int i=0;i<str.length();i++)
        dp[i][i] = 0;

    //Find all length till the length of string
    for(int i=2;i<=str.length();i++) {

        //Now traverse all i length substring in string
        for(int j=0;j<str.length()-i+1;j++) {

            //Find end of current string
            int e = j + i - 1;

            //if char are equal and length is 2 we need 0 operations
            if(str[e] == str[j] && i == 2)
                dp[j][e] = 0;
            //else if length is greater than 2 operations are equal to inside subproblem
            else if(str[e] == str[j])
                dp[j][e] = dp[j+1][e-1];
            else
                //else if char are not equal either we can insert at last or start
                //so it will minimum of these two operations
                dp[j][e] = 1 + min(dp[j+1][e],dp[j][e-1]);
        }
    }

    return dp[0][str.length()-1];
}

main(){
	
	string s;
	int n;
	cin >> n;
	while(n--){
		cin >> s;
		for(int i=0;i<s.length()+1;i++)
            for(int j=0;j<s.length()+1;j++)
                dp[i][j] = INT_MAX;
        cout<<palin(s)<<endl;
	}
}