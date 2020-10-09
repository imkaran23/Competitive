class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_tank = 0, j = 0, sum = 0;
        for (int i=0; i<gas.size(); i++) {       
            sum += gas[i] - cost[i];
            gas_tank += gas[i] - cost[i];       
            if (gas_tank < 0) {
                j = i+1;
                gas_tank = 0;
            }
            
        }
        return sum < 0 ? -1 : j;
    }
};