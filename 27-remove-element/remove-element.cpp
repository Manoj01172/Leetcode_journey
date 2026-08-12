class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int scan=0;
        int write=0;
        while(scan<nums.size()){
            if(nums[scan]==val){
                scan++;
            }
            else if(nums[scan]!=val){
                nums[write]=nums[scan];
                write++;
                scan++;
            }
        }
        return write;
    }
};