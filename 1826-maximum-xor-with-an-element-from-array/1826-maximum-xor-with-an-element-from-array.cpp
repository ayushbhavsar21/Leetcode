struct Node{
    Node* list[2] = {NULL,NULL};
};

void insert(Node*root , int x){
    Node* node = root;
    for(int i=31;i>=0;i--){
        int bit = (x>>i) & 1;
        if(node->list[bit] == NULL){
            node->list[bit] = new Node();
        }
        node = node->list[bit];
    }
}

int maxi(Node*root , int x){
    Node* node = root;
    int ans = 0;
    for(int i=31;i>=0;i--){
        int bit = (x>>i) & 1;
        if(node->list[1 - bit] != NULL){
            ans = ans | (1 << i);
            node = node->list[1 - bit];
        }
        else   
            node = node->list[bit];
    }
    return ans;
}


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        int i =0 ;
        vector<pair<int,pair<int,int>>> q;
        for(auto it:queries){
            q.push_back({it[1],{it[0],i}});
            i++;
        }
        sort(nums.begin(),nums.end());
        sort(q.begin(),q.end());

        Node* root = new Node();
        i = 0;
        for(auto it:q){
            while(i<nums.size() && it.first >= nums[i]){
                insert(root , nums[i]);
                i++;
            }

            if(i!=0){
                ans[it.second.second] = maxi(root , it.second.first);
            }
            else{
                ans[it.second.second] = -1;
            }
        }
        return ans;
    }
};