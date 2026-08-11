class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int max_area=0;
        while(start<end){
            int breadth = end-start;
            int max_height = min(height[start],height[end]);
            int current_area=breadth*max_height;
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
            max_area=max(max_area,current_area);
        }
        return max_area;
    }
};