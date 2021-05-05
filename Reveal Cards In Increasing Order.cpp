// class Solution {
// public:
//     vector<int> deckRevealedIncreasing(vector<int>& deck) {
//         int n = deck.size();
//         if(n<3) return deck;
//         sort(deck.begin(), deck.end(), greater<>());
//         vector<int> v;
        
//         v.push_back(deck[1]);
//         v.push_back(deck[0]);
        
//         for(int i=2; i<n; i++){
//             v.insert(v.begin(),v.back());
//             v.insert(v.begin(),deck[i]);
//             v.pop_back();
//         }
        
//         return v;
//     }
// };

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        if(n<3) return deck;
        sort(deck.begin(), deck.end(), greater<>());
        deque<int> v;
        
        v.push_back(deck[1]);
        v.push_back(deck[0]);
        
        for(int i=2; i<n; i++){
            v.push_front(v.back());
            v.push_front(deck[i]);
            v.pop_back();
        }
        
        for(int i=0; i<n; i++){
            deck[i] = v.front();
            v.pop_front();
        }
        
        return deck;
    }
};