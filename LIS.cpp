/*
An Introduction to the Longest Increasing Subsequence Problem

The task is to find the length of the longest subsequence in a given array of integers such that all elements of the subsequence are sorted in strictly ascending order. This is called the Longest Increasing Subsequence (LIS) problem.

For example, the length of the LIS for  is  since the longest increasing subsequence is .

Here's a great YouTube video of a lecture from MIT's Open-CourseWare covering the topic.


This is one approach which solves this in quadratic time using dynamic programming. A more efficient algorithm which solves the problem in  time is available here.

Given a sequence of integers, find the length of its longest strictly increasing subsequence.

Function Description

Complete the longestIncreasingSubsequence function in the editor below. It should return an integer that denotes the array's LIS.

longestIncreasingSubsequence has the following parameter(s):

arr: an unordered array of integers
Input Format

The first line contains a single integer , the number of elements in .
Each of the next  lines contains an integer, 

Constraints

Output Format

Print a single line containing a single integer denoting the length of the longest increasing subsequence.

Sample Input 0

5
2
7
4
3
8
Sample Output 0

3
Explanation 0

In the array , the longest increasing subsequence is . It has a length of .

Sample Input 1

6
2
4
3
7
4
5
Sample Output 1

4
Explanation 1

The LIS of  is .
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n;
    cin>>n;
    int a[n],dp[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i] && dp[i]<dp[j]+1){
                dp[i] = dp[j] +1;
            }
        }
    }

    int maxi=1;
    for(int i=1;i<n;i++){
        maxi = max(maxi,dp[i]);
    }

    cout<<maxi<<endl;
    return 0;
}

/*
int longestIncreasingSubsequence(vector<int> a) {
    vector<int> subseq;
  int i, tmp;
  for (i = 0; i < a.size(); i++) {
    tmp = lower_bound(subseq.begin(), subseq.end(), a[i]) - subseq.begin();
    if (tmp >= subseq.size())
      subseq.push_back(a[i]);
    else
      subseq[tmp] = a[i];
  }
  return subseq.size();

}
*/