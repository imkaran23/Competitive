
#include<iostream> 
#include <queue> 
#include<cstring>
using namespace std; 

// An entry in queue used in BFS 
struct queueEntry 
{ 
	int v;	 // Vertex number 
	int dist; // Distance of this vertex from source 
}; 
 
int getMinDiceThrows(int move[], int N) 
{ 
    int flag=1;
    for(int i=93;i<100;i++){
        if(move[i]==-1)
            flag=0;
    }
    if(flag)
        return -1;
	bool *visited = new bool[N]; 
	for (int i = 0; i < N; i++) 
		visited[i] = false; 
	queue<queueEntry> q; 
	visited[1] = true; 
	queueEntry s = {1, 0}; // distance of 0't vertex is also 0 
	q.push(s); // Enqueue 0'th vertex 
	queueEntry qe; // A queue entry (qe) 
	while (!q.empty()) 
	{ 
		qe = q.front(); 
		int v = qe.v; // vertex no. of queue entry 
		if (v == N-1) 
			break; 
		q.pop(); 
		for (int j=v+1; j<=(v+6) && j<N; ++j) 
		{ 
			// If this cell is already visited, then ignore 
			if (!visited[j]) 
			{ 
				queueEntry a; 
				a.dist = (qe.dist + 1); 
				visited[j] = true;  
				if (move[j] != -1) 
					a.v = move[j]; 
				else
					a.v = j; 
				q.push(a); 
			} 
		} 
	}  
	return qe.dist; 
} 

int main() 
{ 
	int t,N=101,n,x,y; 
	int moves[N]; 
    cin>>t;
    while(t--){
        memset(moves,-1,sizeof(moves));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            moves[x]=y;
        }
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            moves[x]=y;
        }
        cout<< getMinDiceThrows(moves, N)<<endl;
    } 
	return 0; 
} 
