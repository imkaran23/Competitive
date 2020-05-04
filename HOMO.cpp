/*
HOMO - Homo or Hetero
#ad-hoc-1
Consider a list of numbers with two operations:

insert number — adds the specified number to the end of the list.
delete number — removes the first occurrence of the specified number from the list. If the list does not contain the number specified, no changes are performed.
For example: the result of the insertion of a number 4 to the list [1, 2, 1] is the list [1, 2, 1, 4]. If we delete the number 1 from this list, we get the list [2, 1, 4], but if we delete the number 3 from the list [1, 2, 1, 4], the list stays unchanged.

The list is homogeneous if it contains at least two equal numbers and the list is heterogeneous if it contains at least two different numbers. For example: the list [2, 2] is homogeneous, the list [2, 1, 4] is heterogeneous, the list [1, 2, 1, 4] is both, and the empty list is neither homogeneous nor heterogeneous.

Write a program that handles a number of the operations insert and delete on the empty list and determines list’s homogeneity and heterogeneity after each operation.

Input
The first line of the input file contains an integer number n — the number of operations to handle (1 ≤ n ≤ 100 000).

Following n lines contain one operation description each. The operation description consists of a word “insert” or “delete”, followed by an integer number k — the operation argument (−10^9 ≤ k ≤ 10^9 ).

Output
For each operation output a line, containing a single word, describing the state of the list after the operation:

“both” — if the list is both homogeneous and heterogeneous.
“homo” — if the list is homogeneous, but not heterogeneous.
“hetero” — if the list is heterogeneous, but not homogeneous.
“neither” — if the list is neither homogeneous nor heterogeneous.
Example
Input:
11
insert 1
insert 2
insert 1
insert 4
delete 1
delete 3
delete 2
delete 1
insert 4
delete 4
delete 4

Output:
neither
hetero
both
both
hetero
hetero
hetero
neither
homo
neither
neither
*/
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

main()
{
    vector<long int> v;
    set<long int> set;
    int n;
    long int x;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s>>x;
        if(s=="insert")
        {
            v.push_back(x);
            set.insert(x);
        }
        else
        {
            auto pos= find(v.begin(),v.end(),x);
            if(pos!=v.end())
            {    
                v.erase(pos);
                auto pos= find(v.begin(),v.end(),x);
                if(pos==v.end())
                    set.erase(x);
            }
        }

        if(v.size()<2)
            cout<<"neither\n";
        else
        {
            if(set.size()>1 && set.size()!=v.size())
                cout<<"both\n";
            else if(set.size()==v.size())
                cout<<"hetero\n";
            else if(set.size()==1)
                cout<<"homo\n";
        }

    }
}
