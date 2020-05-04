/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll pos[123456];
ll N, C;

bool F(ll x){
  ll cowsplaced = 1, lastpos = pos[0];
  for(ll i = 1; i < N; i++)
    {
    if(pos[i] - lastpos >= x)
    {
      lastpos = pos[i];
      cowsplaced++;
      if(cowsplaced == C)
      {
        return 1;
      }
    }
  }
  return 0;
}

ll binarySearch()
{

  ll start = 0, ed = pos[N - 1], mx = -1;
  while(start < ed)
    {
    int mid = start + (ed - start)/2;   //prevent overflow
    if(F(mid) == 1)
    {
      if(mid > mx)
        {
        mx = mid;
      }
      start = mid + 1;
    }
    else
    {
      ed = mid;
    }
  }
  return mx;
}

int main()
{
  ll T;
  scanf("%lld",&T);
  while(T--){
    scanf("%lld%lld",&N,&C);
    for(ll i = 0;i<N;i++)
    {
      scanf("%lld",&pos[i]);
    }
    sort(pos, pos + N);
    cout << binarySearch() << "\n";
  }

  return 0;
}
