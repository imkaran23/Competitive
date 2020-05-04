/*
A Tryst With Chess
Attempted by: 2871/Accuracy: 78%/Maximum Score: 20/
 58 Votes
Tag(s): Easy
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
You are given a 10X10 chessboard with a knight on coordinate (I,J). You have to find the number of blocks on the chessboard that the knight can be at in exactly N moves.


The knight can move from its positon in the diagram to all the coordinates marked by X in the following diagram in one move. For the 10X10 chessboard  is the top-left corner, is the top-right corner and  is the bottom-right corner.




Input will consist of three space seperated integers I,J,N

N is less than 10.


Print a single integer denoting the number of blocks on the chessboard that the knight can be at in exactly N moves.

Problem Setter - Sheldon

SAMPLE INPUT 
3 3 1
SAMPLE OUTPUT 
8
Time Limit:	0.5 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include<iostream>
using namespace std;
int arr[10][10];

int recur(int i,int j,int n)
{
    if(n==0)
        return 0;
    if(i<1||i>10||j<1||j>10) 
        return 0;
    if(arr[i][j]==0 && n==0) 
    {
        arr[i][j]=1;
        return 1; 
    } 
    if(arr[i][j]==1 && n==0)
    {
        return 0;
    }

    return recur(i+1,j+2,n-1)+recur(i-1,j+2,n-1)+recur(i+1,j-2,n-1)+recur(i-1,j-2,n-1)+recur(i+2,j+1,n-1)+recur(i-2,j+1,n-1)+recur(i+2,j-1,n-1)+recur(i-2,j-1,n-1);
}

main()
{
    int i,j,n;
    cin>>i>>j>>n;
    cout<<recur(i,j,n);
}