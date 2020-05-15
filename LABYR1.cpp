/*
LABYR1 - Labyrinth
#dfs

The northern part of the Pyramid contains a very large and complicated labyrinth. The labyrinth is divided into square blocks, each of them either filled by rock, or free. There is also a little hook on the floor in the center of every free block. The ACM have found that two of the hooks must be connected by a rope that runs through the hooks in every block on the path between the connected ones. When the rope is fastened, a secret door opens. The problem is that we do not know which hooks to connect. That means also that the neccessary length of the rope is unknown. Your task is to determine the maximum length of the rope we could need for a given labyrinth.

Input
The input consists of T test cases. The number of them (T) is given on the first line of the input file. Each test case begins with a line containing two integers C and R (3 <= C,R <= 1000) indicating the number of columns and rows. Then exactly R lines follow, each containing C characters. These characters specify the labyrinth. Each of them is either a hash mark (#) or a period (.). Hash marks represent rocks, periods are free blocks. It is possible to walk between neighbouring blocks only, where neighbouring blocks are blocks sharing a common side. We cannot walk diagonally and we cannot step out of the labyrinth.

The labyrinth is designed in such a way that there is exactly one path between any two free blocks. Consequently, if we find the proper hooks to connect, it is easy to find the right path connecting them.

Output
Your program must print exactly one line of output for each test case. The line must contain the sentence "Maximum rope length is X." where Xis the length of the longest path between any two free blocks, measured in blocks.

Example
Sample Input:
2
3 3
###
#.#
###
7 6
#######
#.#.###
#.#.###
#.#.#.#
#.....#
#######

Sample output:
Maximum rope length is 0.
Maximum rope length is 8.

#include<iostream>
using namespace std;
#define f(i,a,b) for(int i=int(a);i<=int(b);i++)
char a[1009][1009];
int r,c,x,y,maxi;

void recur(int x,int y,int l){
    cout<<l<<" ";
    if(x<0 || y<0 || x>=r || y>=c || a[x][y]=='#')
        return;
    if(l>maxi)
        maxi=l;
    recur(x,y+1,l+1);
    recur(x,y-1,l+1);
    recur(x+1,y,l+1);
    recur(x-1,y,l+1); 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>c>>r;
        f(i,0,r-1){
            f(j,0,c-1){
                cin>>a[i][j];
                if(a[i][j]=='.')
                {    x=i;y=j;}
            }
        }
        maxi=0;
        recur(x,y,0);
        cout<<maxi<<endl;
    }
}
*/

#include<iostream>
#include <utility>
using namespace std;

#define MAX 1111
#define I first
#define J second

char grid[MAX][MAX];
int R, C, best;
pair <int, int> nxt;

void dfs(int i, int j, int d)
{
	if(i<0 || i>=R || j<0 || j>=C || grid[i][j]!='.') 
        return;
	grid[i][j] = 'v';
	dfs(i+1, j, d+1);
	dfs(i, j+1, d+1);
	dfs(i, j-1, d+1);
	dfs(i-1, j, d+1);
	grid[i][j] = '.';
	if(d > best){
		best = d;
		nxt.I = i;
		nxt.J = j;
	}
}

int find()
{
	int maxlen = 0;
	if(grid[nxt.I][nxt.J]!='.') return 0;
	while(true){
		best = 0;
		dfs(nxt.I, nxt.J, 0);
		if(best <= maxlen) 
            break;
		else 
            maxlen = best;
	}
	return maxlen;
}

int main()
{
	int t, i, j;
	cin>>t;
	while(t--)
	{
		cin>>C>>R;
		for(i=0; i<R; i++)
			scanf("%s", grid[i]);
		nxt.I = nxt.J = 0;
		for(i=0; i<R; i++)
			for(j=0; j<C; j++)
				if(grid[i][j]=='.'){
					nxt.I = i;
					nxt.J = j;
					break;
				}
		printf("Maximum rope length is %d.\n", find());
	}
	return 0;
}