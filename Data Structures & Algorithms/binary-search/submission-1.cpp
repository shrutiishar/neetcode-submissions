class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        int mid=(low+high)/2;
        if(low<=mid){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
        
    }
};
