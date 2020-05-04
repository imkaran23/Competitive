/*
biggest forest
Attempted by: 440/Accuracy: 83%/Maximum Score: 20/
 16 Votes
Tag(s): Easy
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Imagine the field is a 2D plane. Each cell is either water 'W' or a tree 'T'. 
A forest is a collection of connected trees. Two trees are 
connected if they share a side i.e. if they are adjacent to each other.

Your task is, given the information about the field, print the size of the largest forest.

Size of a forest is the number of trees in it. See the sample case for clarity

INPUT:

First line contains the size of the matrix N. 
The next N lines contain N characters each, either 'W' or 'T'.

OUTPUT:

Print the size of the biggest forest.

CONSTRAINTS:

1<=N<=1000

SAMPLE INPUT 
5
TTTWW
TWWTT
TWWTT
TWTTT
WWTTT
SAMPLE OUTPUT 
10
Explanation
The forest on the top left has 6 trees but the forest on the
bottom right is bigger with 10 trees

Time Limit:	5.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB


#include<iostream>
using namespace std;
int n;
char a[1001][1001];

int forest(int i,int j,int& count)
{
    if(i<0||i>n-1||j<0||j>n-1)
        return 0;
    if(a[i][j]=='T')
    {
        a[i][j]='V';
        count++;
    }
    else
    {
        return 0;
    }
    
    
    return forest(i+1,j,count) + forest(i-1,j,count) + forest(i,j+1,count) + forest(i,j-1,count);
}

main()
{
    char c;
    cin>>n;
    for(int i=0 ; i<n ;i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            cin>>c;
            a[i][j]=c;
        }
    }
    
    int count,max=0;
    for(int i=0 ; i<n ;i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            count=0;
            if(a[i][j]=='T')
                forest(i,j,count);
            if(count>max)
                max=count;
        }
    }

    cout<<max;
}
*/

#include<iostream>
using namespace std;
int n;
char a[1001][1001];

void forest(int i,int j,int& count)
{
    if(i<0||i>n-1||j<0||j>n-1)
        return;
    if(a[i][j]=='T')
    {
        a[i][j]='V';
        count++;
    }
    else
        return ;
    
    forest(i+1,j,count);
    forest(i-1,j,count);
    forest(i,j+1,count);
    forest(i,j-1,count);
}

main()
{
    char c;
    cin>>n;
    for(int i=0 ; i<n ;i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            cin>>c;
            a[i][j]=c;
        }
    }
    
    int count,max=0;
    for(int i=0 ; i<n ;i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            count=0;
            if(a[i][j]=='T')
                forest(i,j,count);
            if(count>max)
                max=count;
        }
    }

    cout<<max;
}