/*
A - Frog 1 / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100
 points

Problem Statement
There are 
N
 stones, numbered 
1
,
2
,
…
,
N
. For each 
i
 (
1
≤
i
≤
N
), the height of Stone 
i
 is 
h
i
.

There is a frog who is initially on Stone 
1
. He will repeat the following action some number of times to reach Stone 
N
:

If the frog is currently on Stone 
i
, jump to Stone 
i
+
1
 or Stone 
i
+
2
. Here, a cost of 
|
h
i
−
h
j
|
 is incurred, where 
j
 is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone 
N
.

Constraints
All values in input are integers.
2
≤
N
≤
10
5
1
≤
h
i
≤
10
4
Input
Input is given from Standard Input in the following format:

N

h
1
 
h
2
 
…
 
h
N

Output
Print the minimum possible total cost incurred.

Sample Input 1 
Copy
4
10 30 40 20
Sample Output 1 
Copy
30
If we follow the path 
1
 → 
2
 → 
4
, the total cost incurred would be 
|
10
−
30
|
+
|
30
−
20
|
=
30
.

Sample Input 2 
Copy
2
10 10
Sample Output 2 
Copy
0
If we follow the path 
1
 → 
2
, the total cost incurred would be 
|
10
−
10
|
=
0
.

Sample Input 3 
Copy
6
30 10 60 10 60 50
Sample Output 3 
Copy
40
If we follow the path 
1
 → 
3
 → 
5
 → 
6
, the total cost incurred would be 
|
30
−
60
|
+
|
60
−
60
|
+
|
60
−
50
|
=
40
.


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1e9 + 5;

int main(){
    int n,x;
    cin>>n;
    vector<int> h;
    for(int i=0;i<n;i++){
        cin>>x;
        h.push_back(x);
    }
    
    vector<int> dp(n,INF);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);

    for(int i=2;i<n;i++){
        dp[i] = min( dp[i-1] + abs(h[i]-h[i-1]) ,
                     dp[i-2] + abs(h[i]-h[i-2]) );
    }
    cout<<dp[n-1]<<endl;
    return 0;
}