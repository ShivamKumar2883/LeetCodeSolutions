class Solution {
    int rec(vector<int>& nums,int&OR,int o=0,int i=0){
        if(nums.size()==i){if(o==OR)return 1;
        return 0;}
     return rec(nums,OR,o,i+1)+rec(nums,OR,o|nums[i],i+1);
    }
public: 
    int countMaxOrSubsets(vector<int>& nums) {
        int OR=0;
        for(int&a:nums) OR=OR|a;
        return rec(nums,OR);
    }
};