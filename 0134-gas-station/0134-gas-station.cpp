class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currentGas = 0, start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            // If we can't proceed from this station
            if (currentGas < 0) {
                start = i + 1;  // Try starting from the next station
                currentGas = 0; // Reset current gas
            }
        }
        
        // Check if total gas is enough to cover total cost
        return (totalGas >= totalCost) ? start : -1;
    }
};
