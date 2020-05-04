/*
Let  be a binary string of length N. Then let's define  as an infinite string with  (informally,  is the concatenation of P with itself an infinite number of times).

Define the GCD-string of two integers , with  to be a binary string of length a that satisfies the following:

 =  (1 followed by  zeros ) if a is divisible by b
 = First a characters of  otherwise
We can define  to be the value of the integer represented by the binary string  in base-2. Given T pairs of integers , compute  for each pair.

Input Format:
The first line will contain the number of test cases T.
Each test case can be described with a single line containing two integers .

Output Format:
Output T numbers, the answers to each problem.

Constraints
For all subtasks:


File 1 (70 pts)

File 2 (30 pts)

SAMPLE INPUT 
5
3 1
3 2
5 2
10 4
100 3
SAMPLE OUTPUT 
4
5
21
546
986497880
Explanation
The base 2 results for the first four samples are as follows

Time Limit:	2.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include<iostream>
using namespace std;

string gcd_string(int x, int y)
{
    if(x%y == 0)
    {
        string s="1";
        for(int i = 0; i<x-1 ; i++)
        {
            s+="0";
        }
        return s;
    }
    else
    {
        string s1="";
        string s = gcd_string(y,x%y);
        for(int i = 0; i<x ; i++)
        {
            int n = s.size();
            s1+=s[i%n];
        }
        return s1;
    } 
}

main()
{
    int t,x,y,number;
    cin>>t;
    while(t--)
    {
        number = 0;
        cin>>x>>y;
        string str = gcd_string(x,y);
        for(int i = 0; i<str.size() ; i++)
        {
            if(str[i]=='1')
            {
                number = (number%1000000007 + (1<<(str.size()-i-1))%1000000007) % 1000000007 ;
            }
        }
        cout<<number<<endl;
    }
}