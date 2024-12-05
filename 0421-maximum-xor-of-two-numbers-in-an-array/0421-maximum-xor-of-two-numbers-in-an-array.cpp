struct Node{
    Node* list[2];

};
void insert(Node* root,int x){
    Node* node = root;
    for(int i=31;i>=0;i--){
        int bit  = (x>>i) & 1;
        if(node->list[bit] == NULL){
            node->list[bit] = new Node();
        }
        node = node->list[bit];
    }
}
int maxi(Node* root,int x){
    Node* node = root;
    int ans= 0;
    for(int i=31;i>=0;i--){
        int bit  = (x>>i) & 1;
        if(node->list[1 - bit] != NULL ){
            ans = ans | (1 << i) ;
            node = node->list[1 - bit];
        }
        else 
            node = node->list[bit];
    }
    return ans;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();

        for(int i=0;i<nums.size();i++){
            insert(root, nums[i]);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans = max(ans , maxi(root , nums[i]));
        }
        return ans;

    }
};