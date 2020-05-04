/*
You will be given an array of integers. All of the integers except one occur twice. That one is unique in the array.

Given an array of integers, find and print the unique element.

For example, , the unique element is .

Function Description

Complete the lonelyinteger function in the editor below. It should return the integer which occurs only once in the input array.

lonelyinteger has the following parameter(s):

a: an array of integers
Input Format

The first line contains a single integer, , denoting the number of integers in the array.
The second line contains  space-separated integers describing the values in .

Constraints

It is guaranteed that  is an odd number and that there is one unique element.
, where .
Output Format

Print the unique integer in the array.

Sample Input 0

1
1
Sample Output 0

1
Explanation 0

There is only one element in the array, thus it is unique.

Sample Input 1

3
1 1 2
Sample Output 1

2
Explanation 1

We have two 's, and  is unique.

Sample Input 2

5
0 0 1 2 1
Sample Output 2

2
Explanation 2

We have two 's, two 's, and one .  is unique.


*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
    int n,result=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        result^=a[i];
    }
    cout<<result<<endl;
}