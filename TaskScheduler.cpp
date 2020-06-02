// https://leetcode.com/problems/task-scheduler
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int count=0;
        for(auto t : tasks){
            mp[t]++;
            count = max(count,mp[t]);
        }
        int ans = (count-1)*(n+1);
        for(auto x : mp) if(x.second == count) ans++;
        return max(ans,(int)tasks.size());
    }
};