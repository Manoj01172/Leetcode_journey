class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        map<int, int> first;
        map<int, int> last;
        for(int i =0;i<nums.size();i++){
            freq[nums[i]]++;
            if(first.find(nums[i])==first.end()){
                first[nums[i]]=i;
            }
            last[nums[i]]=i;
        }
        int degree = 0;
        for(auto p : freq){
            degree = max(degree,p.second);
        }
        int ans = nums.size();
        for(auto p :freq){
            if(p.second == degree){
                int len = last[p.first] - first[p.first] + 1;
                ans = min(ans,len);
            }
        }
        return ans;
    }
};