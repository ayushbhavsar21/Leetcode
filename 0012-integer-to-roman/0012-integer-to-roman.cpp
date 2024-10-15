class Solution {
public:
    
    string solve(int x, int place) {
        string ones, fives, tens;
        
        
        if (place == 1) {        // Units
            ones = "I"; fives = "V"; tens = "X";
        } else if (place == 10) { // Tens
            ones = "X"; fives = "L"; tens = "C";
        } else if (place == 100) { // Hundreds
            ones = "C"; fives = "D"; tens = "M";
        } else if (place == 1000) { // Thousands
            ones = "M"; 
        }
        
        
        if (x >= 1 && x <= 3) {
            return string(x, ones[0]); // Repeat ones symbol x times
        } else if (x == 4) {
            return ones + fives;       // 4 is represented as "IV"
        } else if (x >= 5 && x <= 8) {
            return fives + string(x - 5, ones[0]); // 5-8 as "V", "VI", etc.
        } else if (x == 9) {
            return ones + tens;        // 9 is represented as "IX"
        }
        return "";
    }

    string intToRoman(int num) {
        string ans = "";
        vector<int> placeValues = {1000, 100, 10, 1};
        int idx = 0;
        
        for (int place : placeValues) {
            int digit = num / place; 
            num %= place; 
            if (digit > 0) {
                ans += solve(digit, place); 
            }
        }
        
        return ans;
    }
};
