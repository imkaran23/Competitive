/*
Little Jhool and his addiction! [2]
Attempted by: 1401/Accuracy: 74%/Maximum Score: 20/
 54 Votes
Tag(s): Easy, Greedy algorithm, Sorting
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Little Jhool is an addict. No, unlike the usual drug addicts, he's an addict of the good kind: the shopping addict. Some of his friends also call him a shopaholic, though he tries his level best to deny the title given to him by his friends. Now, he has some favorite websites as we already have seen in another question from where he always likes to buy things.

Anyway. As we already know, girls are crazy for Jhool and would do anything to be with him. It's no different this time. Little Jhool has n girlfriends, and every one of them wants to go e-shopping with him. Every single girl has a list with her which has Xi number of items to be bought. Jhool himself has n different lists to go shopping with every girlfriend - each list having some specific number of things to be bought. There are (n+n=2n) number of lists. So, the number of lists is always going to be even.

Now, Jhool does NOT want to upset his girlfriends! (Obviously!) So, he comes up with a devious plan to save the trouble. What he does is this:

He takes all the n lists of items his girlfriends need to purchase, and his n lists and mixes all of them up and randomly gives everyone a list.
Now, no one can recognize their original list. Since the objective was spending time with each other, no one even cares.
Consider the scenario that it takes one unit of time to get one item from any list.
Now, if Little Jhool picks up a list with 12 items, for instance and pairs himself with a girl with 8 items: the total amount they'll spend together would be: (12 + 8 = 20 units of time!)
If a girl gets to spend more time with Jhool, she'll be happy, and the ones who wouldn't get much time would obviously be pissed. And Jhool doesn't want that to happen. So, he wants to pair up all the lists in such a way that the difference between the girl he's going to spend the maximum time with, and the girl he's going to spend the minimum time with is minimized!

We are also given a constant factor, k, if the minimum value is greater than this constant, his girlfriends would leave him, figuring out the bluff. If k would be equal to the minimum value, he would be just saved. And if it would be less, he would remain the magnet he is!

PS: We apologize on behalf of Little Jhool. We know that he has a bad habit of landing himself in a fix all the time. Just help him this one last time, come on!

Input format:
The first line contains the number of test cases. The first line of the test cases contains two integers: 2n and k, which is followed by a vector representing all the 2n lists.

Output format:
Print the minimum difference possible by pairing different lists. Also, print:
- No more girlfriends! when ans > k.
- Lucky chap! when ans == k.
- Chick magnet Jhool! when ans < k.

Constraints:
1 ≤ Test Cases ≤ 50
2 ≤ 2n ≤ 106 - No. of lists.
1 ≤ Xi ≤ 106 - No. of items in a list.
0 ≤ k ≤ 106

SAMPLE INPUT 
3
2 1
4 2
6 4
1 6 6 7 1 8
4 0
2 6 4 3
SAMPLE OUTPUT 
0
Chick magnet Jhool!
4
Lucky chap!
1
No more girlfriends!
Explanation
In the first case, since there will be only one pair, the minimum would be 0, which is less than the value of k. In the second test case, the value of k == 4, minimum value would be: [(8+1), (7+1), (6+6)] so, 12-8 == 4 which is equal to k. In the third case, k is greater than the answer, which is 1. [(6+2), (4+3)] -> [8-7] -> 1.

Time Limit:	2.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n2,k;
        cin>>n2>>k;
        vector<int> v;
        for(int i=0;i<n2;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        set<int> s;
        for(int i=0;i<n2/2;i++)
        {
            s.insert(v[i]+v[n2-1-i]);
        }
        int ans = *(--s.end()) - *s.begin();
        cout<<ans<<endl;
        if(ans>k)
            cout<<"No more girlfriends!\n";
        else if(ans==k)
            cout<<"Lucky chap!\n";
        else
            cout<<"Chick magnet Jhool!\n";
    }
}