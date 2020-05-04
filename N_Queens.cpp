/*
N-Queens
Attempted by: 3240/Accuracy: 88%/Maximum Score: 20/
 77 Votes
Tag(s): Backtracking, Easy
PROBLEM
EDITORIAL
MY SUBMISSIONS
ANALYTICS
Given a chess board having  cells, you need to place N queens on the board in such a way that no queen attacks any other queen.

Input:
The only line of input consists of a single integer denoting N.

Output:
If it is possible to place all the N queens in such a way that no queen attacks another queen, then print N lines having N integers. 
The integer in  line and  column will denote the cell  of the board and should be 1 if a queen is placed at  otherwise 0. 
If there are more than way of placing queens print any of them. If it is not possible to place all N queens in the desired way, 
then print "Not possible" (without quotes).

Constraints:
.

SAMPLE INPUT 
4
SAMPLE OUTPUT 
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 
Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void fill(int x,int y,vector<vector<int> > &a,int n)
{
    for(int j=0; j<n ; j++)
    {
        if(a[x][j]==-1)
            a[x][j]=0;
    }

    for(int i=0; i<n ; i++)
    {
        if(a[i][y]==-1)
            a[i][y]=0;
    }

    int k=y;

    for(int i=x; i<n ; i++)
    {
        if(y<n && a[i][y]==-1)
        {
            a[i][y]=0;
        }
        y++;
    }

    for(int i=n; i>=0 ; i--)
    {
        if(k<n && a[i][k]==-1)
        {   
            a[i][k]=0;
        }
        k--;
    }
    
}

void nqueen(int x,int y,vector<vector<int> > &a,int n)
{
    a[x][y]=1;
    fill(x,y,a,n);
    for (int j=0;j<n;j++)
    {
        if(x+1<n && a[x+1][j]==-1)
        {
            nqueen(x+1,j,a,n);
            // return 1;
        }
        // else if(x+1<n && a[x+1][n]==0)
        // {
        //     return 0;
        // }
        // else
        // {
        //     return 1;
        // }    
    }
}

main()
{
    int n,flag;
    cin>>n;
    // vector<vector<int> > a(n,vector<int> (n,-1));
    for ( int y=0 ; y<=(n-1)/2; y++)
    {
        vector<vector<int> > a(n,vector<int> (n,-1));
        nqueen(0,y,a,n);
        flag = 1;
        for ( int x=0 ; x<n ; x++)
        {
            int count = 0;
            for ( int y=0 ; y<n ; y++)
            {
                if(a[x][y]==0)
                    count++;
            }
            if(count==n)
            {
                flag=0;
                break;
            }
        }

        if(flag)
        {
            for ( int x=0 ; x<n ; x++)
            {
                for ( int y=0 ; y<n ; y++)
                    cout<<a[x][y]<<" ";
                cout<<endl;
            }
            break;
        }  
    }

    if(!flag)
        cout<<"Not possible";
}