class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if(v1.size() > v2.size())
            return findMedianSortedArrays(v2,v1);

        int n1 = v1.size() , n2 = v2.size();

        int left = 0, right = n1;

        while(left <= right){
            int part1 = (left + right)/2;
            int part2 = (n1 + n2 + 1)/2 - part1;

            int maxleft1 = (part1 == 0) ? INT_MIN : v1[part1 - 1];
            int minright1 = (part1 == n1) ? INT_MAX : v1[part1];
            int maxleft2 = (part2 == 0) ? INT_MIN : v2[part2 - 1];
            int minright2 = (part2 == n2) ? INT_MAX : v2[part2];

            if(maxleft1 <= minright2 && maxleft2 <= minright1){
                if((n1 + n2 )%2 == 0)
                    return (max(maxleft1 , maxleft2) + min(minright1 , minright2))/2.0;
                else
                    return max(maxleft1 , maxleft2);
            }
            if(maxleft1 > minright2)
                right = part1 -1;
            else
                left = part1 +1;
            
        }
        return 0.0;
    }
};