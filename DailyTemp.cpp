// https://leetcode.com/problems/daily-temperatures

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         vector<int> result(T.size(),0);
//         for(int i=0; i<T.size() ; i++){
//             for(int j=i+1; j<T.size(); j++){
//                 if(T[j]>T[i]){
//                     result[i]=j-i;
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T){
        vector<int> result(T.size(),0);
        stack<pair<int,int> > s;
        
        for(int i=0; i<T.size() ; i++){
            while(!s.empty() && T[i]>s.top().first){
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push(make_pair(T[i],i));
        }
        
        return result;
    } 
};