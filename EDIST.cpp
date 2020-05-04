/*
EDIST - Edit distance
#dynamic-programming

You are given two strings, A and B. Answer, what is the smallest number of operations you need to
transform A to B?

Operations are:

Delete one letter from one of strings
Insert one letter into one of strings
Replace one of letters from one of strings with another letter
Input
T - number of test cases

For each test case:

String A
String B
Both strings will contain only uppercase characters and they won't be longer than 2000 characters. 

There will be 10 test cases in data set.

Output
For each test case, one line, minimum number of operations.

Example
Input:
1
FOOD
MONEY

Output:
4
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

main(){
    int t;
    string s1,s2;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        int m = s1.size();  
        int n = s2.size();  
        int dp[m + 1][n + 1];  
        memset(dp, 0, sizeof(dp));  
        for (int i = 1; i <= n; i++) {  
            dp[0][i] = i;  
        }  
        for (int i = 1; i <= m; i++) {  
            dp[i][0] = i;  
        }  
        for (int i = 1; i <= m; i++) {  
            for (int j = 1; j <= n; j++) {  
                if (s1[i - 1] == s2[j - 1]) {  
                    dp[i][j] = dp[i - 1][j - 1]; // no operation required as characters are the same  
                }  
                else {  
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],    // substitution  
                            min(dp[i][j - 1],     // insertion  
                                dp[i - 1][j]));    // deletion  
                }  
            }  
        }  
        cout<< dp[m][n] <<endl;  
    }
}