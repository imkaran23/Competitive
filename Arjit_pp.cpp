/*
Arjit and Printing Press
Attempted by: 3106/Accuracy: 65%/Maximum Score: 20/
 102 Votes
Tag(s): Easy, Greedy algorithm
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Arjit has his own printing press, Bainik Dhaskar (BD). He feels that words on their own simply aren't beautiful enough. So, he wishes to make a Super Manuscript (SM) machine. Now what does this machine do?
The SM machine aims to make words as beautiful as they can be by making a word as lexicographically small as possible. Arjit, being the resourceful person he is, has a reserve string from which we can choose characters that will replace characters in the original word that BD's SM machine wishes to transform.
Keep in mind that once you have used a letter in the reserve string, it is removed from the reserve.
As Arjit is busy with other work at BD, it's your work to take care of programming SM :)
Note that you cannot modify the original order of the letters in the word that has to be transformed. You can only replace its letters with those in the reserve.

Input:
The first line of input contains T. T test cases follow.
Each test case has 2 lines.
The first line of each test case has the word W, that has to be transformed.
The second line of each test case has a reserve R from which we will pick letters.

Output:
The output should contain T lines with the answer to each test on a new line.
Print a word P which is the lexicographically smallest that can be obtained on replacing letters of W with letters from R.

Constraints:

 4
 4
W and R will contain only lowercase characters.

See the example to understand this better.

SAMPLE INPUT 
3
bbbb
aaa
zxewya
abcd
ac
zzzb
SAMPLE OUTPUT 
aaab
abcdya
ab
Explanation
In the first test case, we have 3 , so we simply replace the first 3 letters of the word.
In the second test case, again we just replace the first 4 letters with  and d.
In the third case, b is lexicographically smaller than c, so  becomes .

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/
#include<iostream>
#include<algorithm>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string w,r;
        cin>>w>>r;
        sort(r.begin(),r.end());
        int i=0;
        for(int j=0;j<w.size();j++)
        {
            if(i>=r.size())
                break;
            if(r[i]<w[j])
            {    
                w[j]=r[i];
                i++;
            }
            // cout<<w<<endl<<r<<endl;
        }
        cout<<w<<endl;
    }
}