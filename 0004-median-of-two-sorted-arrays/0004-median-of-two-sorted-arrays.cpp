class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        double ans=-1;

        vector<int> v;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n2){
            v.push_back(nums2[j]);
            j++;
        }

        for(auto i:v){
            cout<<i<<" ";
        }cout<<endl;

        if((n1 + n2)%2 ==0   ){
            ans = ((double)v[(n1 + n2)/2] + (double)v[(n1 + n2)/2 - 1] )/2;
        }
        else{
            ans = v[(n1 + n2)/2] ;
        }

        return ans;
    }
};