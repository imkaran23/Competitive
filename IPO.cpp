#define f first
#define s second

class Solution {
public:
    
    int findMaximizedCapital(int k, int W, vector<int>& p, vector<int>& c) {
       
        int n = p.size();
        vector<pair<int,int>> projects;
        priority_queue<int> pq;
        for(int i=0 ; i<n ; i++) projects.push_back({p[i],c[i]});
        sort(projects.begin(),projects.end(),[&](pair<int,int> a,pair<int,int> b){ return a.s<b.s;});
        
        int i=0;
        while(k--){
            while(i<n && projects[i].s<=W)     
                pq.push(projects[i++].f);
            
            if(!pq.empty()){
                W += pq.top();
                pq.pop();
            }
        }

        return W;
    }
};