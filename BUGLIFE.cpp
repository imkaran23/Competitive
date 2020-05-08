/*
BUGLIFE - A Bug’s Life
#graph-theory #graph #dfs

Professor Hopper is researching the sexual behavior of a rare species of bugs. He assumes that they feature two different genders and that they only interact with bugs of the opposite gender. In his experiment, individual bugs and their interactions were easy to identify, because numbers were printed on their backs.

Given a list of bug interactions, decide whether the experiment supports his assumption of two genders with no homosexual bugs or if it contains some bug interactions that falsify it.

Input
The first line of the input contains the number of scenarios. Each scenario starts with one line giving the number of bugs (at least one, and up to 2000) and the number of interactions (up to 1000000) separated by a single space. In the following lines, each interaction is given in the form of two distinct bug numbers separated by a single space. Bugs are numbered consecutively starting from one.

Output
The output for every scenario is a line containing “Scenario #i:”, where i is the number of the scenario starting at 1, followed by one line saying either “No suspicious bugs found!” if the experiment is consistent with his assumption about the bugs’ sexual behavior, or “Suspicious bugs found!” if Professor Hopper’s assumption is definitely wrong.

Example
Input:
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4

Output:
Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found!
*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
bool ans;
int color[2002];
vector<vector<int> > v;

void dfs(int x){
    if(!ans)
        return;
    if(color[x]==-1)
        color[x]=1;
    f(i,0,v[x].size()-1){
        int y=v[x][i];
        if(color[y]==-1){
            color[y]=!color[x];
            dfs(y);
        }
        else if(color[y]==color[x]){
            ans=false;
            return;
        }
    }
}

int main(){
    int t,n,inter,x,y;
    cin>>t;
    f(k,1,t){
        cin>>n>>inter;
        v.clear();
        v.resize(n+1);
        while(inter--){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        ans=true;
        memset(color,-1,sizeof(color));
        f(i,1,n){
            if(color[i]==-1)
                dfs(i);
        }

        cout<< "Scenario #" << k << ":" << endl ;
        if(!ans)
            cout<< "Suspicious bugs found!" << endl ;
        else 
            cout<< "No suspicious bugs found!" << endl ;
    }
    return 0;
}