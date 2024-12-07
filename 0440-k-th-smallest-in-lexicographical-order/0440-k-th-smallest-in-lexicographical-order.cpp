class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1; 
        k--; 

        while (k > 0) {
            int steps = calculateSteps(current, n); 
            if (steps <= k) {
                // Skip this prefix
                k -= steps;
                current++;
            } else {
                // Move to the next level in the prefix tree
                k--;
                current *= 10;
            }
        }

        return current;
    }


    int calculateSteps(long long current, long long n) {
        long long steps = 0;
        long long first = current;
        long long last = current;

        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }
};


