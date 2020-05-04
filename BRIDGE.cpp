/*
BRIDGE - Building Bridges
#tree #binary-search

The tribe soon discovers that just communication is not enough and wants to meet each other to form a joint force against the terminator. But there is a deep canyon that needs to crossed. Points have been identified on both sides on which bridge ends can be made. But before the construction could be started, a witch Chudael predicted that a bridge can only be built between corresponding end points, i.e. a bridge starting from the ith end point on one side can only end on the ith end point on the other side, where the position of end points is seen in the order in which the points were identified. If not, it would lead to the end of the tribe. The tribe just wants to make as many non-cutting bridges as possible, with the constraint in mind. Bridges "cut" if and only if they have exactly one common point that is not an end point.

Input
The first line of the input contains test cases t (1<=t<=50). It is followed by 3*t lines, 3 for each test case. The first line of input for each test case contains the number of end points identified on each side, n (1<=n<=103). The second line contains x-coordinates of end points identified on the first side and similiarly the third line contains the x-coordinates of corresponding end points identified on the other side. The end points are inputted in the order in which they were identified. The x-coordinates can range between -103 to 103.

Output
You are required to output a single line for each test case. The line contains a single integer – the maximum number of bridges possible with the constraints explained above.

Example
Input:
3
4

2 5 8 10

6 4 1 2

3

5 3 10

6 4 1

6

1 2 3 4 5 6

3 4 5 6 1 2

Output:
2

2

4

 

Expalanation: For the first test case, two non-overlapping bridges can be formed between the 3rd and 4th end points on each side.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< pair< int ,int  > > vec;
int dp[1111], a[1111], b[1111];

main(){
    int t,N;
    cin>>t;
    while (t--){
        cin>>N;
        vec.clear();
     for (int i=0;i<N;i++)
     {
         cin>>a[i];
     }
     for (int i=0;i<N;i++)
     {
         cin>>b[i];
     }
     for (int i=0;i<N;i++)
     {
         vec.push_back(pair<int,int>(a[i],b[i]));
     }
     int maxi=0;
     sort(vec.begin(),vec.begin()+N);
      for(int i=0;i<N;i++)
      {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
           if(vec[i].second>=vec[j].second && dp[i]<dp[j]+1)
           {dp[i]=dp[j]+1;}
        }
        maxi=max(dp[i],maxi);
      }
cout<<maxi<<endl;
    }
    
}