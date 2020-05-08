/*
CAM5 - prayatna PR
#dfs

help the Prayatna pr team
Well, the annual technical symposium of Department of Computer Technology is around the corner. All that we need, to make it a grand success is Publicity among the peer groups ( ofCourse the sponsors too :P ). We decided to share the job between the student groups. As per the plan we decided to meet people in person and influence them to attend Prayatna. But to meet them we have to go to various student groups. To do so, we had to cut our classes. But being studious. students refused to cut more classes. Instead of meeting every one in person we decided to meet few people such that the person to whom we pass the news will spread it to all his friends. And those friends will pass it to other friends and so on. Your task is to find the number of people to be met by the organizers to spread the news.

Caution: Large I/O

Input
First line of input is 't' - Test cases. Follwed by N, the number of peers in the testcase ( 0 to N-1 ). followed by the number of friend description 'e'. Following are 'e' descriptions of type "a b" denoting 'a' friends with 'b'. If 'a' is friends with 'b' then 'b' is friends with 'a'.

Output
Output contains t line, the number of people, the organizers have to meet in person for each test case.

Example
Input:
2

4
2
0 1
1 2

3
0

Output:
2
3
Explanation
case 1 : 0 is friends with 1; 1 is friends with 2; so if we pass the news to 0 & 3, news will pass it to the entire N peers.

case 2 : no one is friends with any one. So we have to meet every one in person.

Constraints
t = 10
2 <= N <= 100000
0 <= e <= N/2
*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
vector<vector<int> > v;
vector<bool> vis;

void dfs(int x){
    vis[x]=true;
    f(i,0,v[x].size()-1){
        if(!vis[v[x][i]])
            dfs(v[x][i]);
    }
}

int main(){
    int t,n,e,x,y;
    cin>>t;
    while(t--){
        cin>>n>>e;
        v.clear();
        v.resize(n);
        while(e--){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int count=0;
        vis.clear();
        vis.resize(n);
        f(i,0,n-1){
            if(!vis[i]){
                count++;
                dfs(i);
            }
        }
        cout<<count<<endl;
    }
    return 0;
}