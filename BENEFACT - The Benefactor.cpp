/*
BENEFACT - The Benefactor
#shortest-path #dfs
Another chapter of the municipal chronicles of a well known unbelievable lordly major town (if this town is not well known to you,
you might want to solve problem CSTREET first) tells us the following story:

Once upon a time the citizens of the unbelievable lordly major town decided to elect a major.
At that time this was a very new idea and election campaigns were completely unknown. But of course several citizens wanted to become major and
it didn't took long for them to find out, that promising nice things that never will become real tends to be useful in such a situation.
One candidate to be elected as a major was Ivo sometimes called the benefactor because of his valuable gifts to the unbelievably lordly major towns
citizens.

One day before the election day Ivo the benefactor made a promise to the citizens of the town.
In case of his victory in the elections he would ensure that on one of the paved streets of the town street lamps would be erected and
that he would pay that with his own money. As thrifty as the citizens of the unbelievable lordly major town were, they elected him and
one day after the elections they presented him their decision which street should have street lamps. Of course they chose not only the longest of all
streets but renamed several streets so that a very long street in the town existed.

Can you find how long this street was? To be more specific, the situation is as follows. You are presented a list of all paved streets in the
unbelievable lordly major town. As you might remember from problem CSTREET in the town the streets are paved in a way that between every two points
of interest in the town exactly one paved connection exists. Your task is to find the longest distance that exists between any two places of interest
in the city.

Input
The first line of input contains the number of testcases t.
The first line of each testcase contains the number of places (2 <= n <= 50000) in the town. Each street is given at one line by two places
(1 <= a, b <= n) and the length of the street (0 <= l < 20000).

Output
For each testcase output one line which contains the maximum length of the longest street in the city.

Example
Input:
1
6
1 2 3
2 3 4
2 6 2
6 4 6
6 5 5

Output:
12
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int t,n,x,y,weight;
        cin>>t;
        while(t--)
        {
            cin>>n;
            vector<pair<int,int> > v[n+1];
            for (int i = 0; i < n-1; ++i)
            {
			scanf("%d%d%d",&x,&y,&weight);
			v[x].push_back(make_pair(y,weight));
			v[y].push_back(make_pair(x,weight));
            }
            int visited[n+1];
            memset(visited,-1,sizeof(visited));

            int max=INT_MIN,max_idx,max_val;
            queue<pair<int,int> >Q;
            int val,idx;
            pair<int,int> p;
            Q.push(v[x].front());
            visited[v[x].front().first]=0;
            while(!Q.empty())
            {
                p=Q.front();
                Q.pop();
                idx=p.first;
                val=p.second;
                for (int i = 0; i < v[idx].size(); ++i)
                {
                    int index=v[idx][i].first;
                    int value =v[idx][i].second;
                    if (visited[index]==-1)
                    {
                        Q.push(v[idx][i]);
                        visited[index]=visited[idx]+value;
                        if(visited[index] > max)
                        {
                            max=visited[index];
                            max_idx=index;
                            max_val=value;
                        }
                    }
                }
            }
            memset(visited,-1,sizeof(visited));
            Q.push(make_pair(max_idx,max_val));
            visited[max_idx]=0;

            while(!Q.empty())
            {
                p=Q.front();
                Q.pop();
                idx=p.first;
                val=p.second;
                for (int i = 0; i < v[idx].size(); ++i)
                {
                    int index=v[idx][i].first;
                    int value =v[idx][i].second;
                    if (visited[index]==-1)
                    {
                        Q.push(v[idx][i]);
                        visited[index]=visited[idx]+value;
                        if(visited[index] > max)
                        {
                            max=visited[index];
                        }
                    }
                }
            }
            printf("%d\n", max);
        }
        return 0;
}

