class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                count++;
                break;
            }
        }
        if(count){
            return true;
        }
        else{
            return false;
        }
    }
};